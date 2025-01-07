#include <rational/rational.hpp>

#include <iostream>
#include <exception>
#include <string>

Rational::Rational(const int32_t num) noexcept
    :Rational(num, 1)
{
}

Rational::Rational(const int32_t num, const int32_t denom) {
    if (denom == 0) {
        throw std::invalid_argument("division by zero");
    }
    num_ = num;
    denom_ = denom;
    normalize();
}

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept {
    return rhs.writeTo(ostrm);
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const noexcept {
    ostrm << num_ << separator << denom_;
    return ostrm;
}

std::istream& operator>>(std::istream& istrm, Rational& rhs) noexcept {
    return rhs.readFrom(istrm);
}

std::istream& Rational::readFrom(std::istream& istrm) noexcept {
    int32_t num(0);
    int32_t denom(1);
    char division_symbol(0);
    while (!istrm.eof()) {
        char symb = istrm.get();
        if (symb != ' ') {
            istrm.unget();
            break;
        }
    }
    istrm >> std::noskipws >> num >> division_symbol >> denom;
    if (istrm.good() || !istrm.fail() && istrm.eof()) {
        if (Rational::separator == division_symbol) {
            *this = Rational(num, denom);
            if (denom < 0) {
                istrm.setstate(std::ios_base::failbit);
            }
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}

Rational& Rational::operator+=(const Rational& rhs) noexcept {
    num_ = num_ * rhs.denom_ + rhs.num_ * denom_;
    denom_ = denom_ * rhs.denom_;
    normalize();
    return *this;
}

Rational& Rational::operator-=(const Rational& rhs) noexcept {
    num_ = num_ * rhs.denom_ - rhs.num_ * denom_;
    denom_ = denom_ * rhs.denom_;
    normalize();
    return *this;
}

Rational& Rational::operator*=(const Rational& rhs) noexcept {
    num_ = num_ * rhs.num_;
    denom_ = denom_ * rhs.denom_;
    normalize();
    return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
    if (rhs.num_ == 0) {
        throw std::invalid_argument("division by zero");
    }
    num_ = num_ * rhs.denom_;
    denom_ = denom_ * rhs.num_;
    normalize();
    return *this;
}

Rational& Rational::operator*=(const int32_t& rhs) noexcept {
    num_ *= rhs;
    normalize();
    return *this;
}
Rational& Rational::operator+=(const int32_t& rhs) noexcept {
    num_ += rhs * denom_;
    return *this;
}
Rational& Rational::operator-=(const int32_t& rhs) noexcept {
    num_ -= rhs * denom_;
    normalize();
    return *this;
}
Rational& Rational::operator/=(const int32_t& rhs) {
    denom_ *= rhs;
    normalize();
    return *this;
}

Rational Rational::operator-() noexcept {
    num_ = -num_;
    return *this;
}

bool Rational::operator==(const Rational& rhs) const noexcept { return (num_ == rhs.num_) && (denom_ == rhs.denom_); }
bool Rational::operator!=(const Rational& rhs) const noexcept { return !operator==(rhs); }
bool Rational::operator>(const Rational& rhs) const noexcept { return ((num_ * rhs.denom_ - rhs.num_ * denom_) > 0); }
bool operator<(const Rational& lhs, const Rational& rhs) { return rhs.operator>(lhs); }
bool operator<=(const Rational& lhs, const Rational& rhs) { return !lhs.operator>(rhs); }
bool operator>=(const Rational& lhs, const Rational& rhs) { return !rhs.operator>(lhs); }

bool Rational::operator==(const int32_t& rhs) const noexcept { return (num_ == rhs) && (denom_ == 1); }
bool Rational::operator!=(const int32_t& rhs) const noexcept { return !operator==(rhs); }
bool Rational::operator>(const int32_t& rhs) const noexcept { return ((num_ - rhs * denom_) > 0); }
bool Rational::operator<(const int32_t& rhs) const noexcept { return ((num_ - rhs * denom_) < 0); }
bool Rational::operator>=(const int32_t& rhs) const noexcept { return ((num_ - rhs * denom_) >= 0); }
bool Rational::operator<=(const int32_t& rhs) const noexcept { return ((num_ - rhs * denom_) <= 0); }
