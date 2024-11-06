#include <complex/complex.hpp>

Complex Complex::operator-() const noexcept { return Complex(-re, -im); }

bool Complex::operator==(const Complex& rhs) const noexcept {
	return re == rhs.re && im == rhs.im;
}
bool Complex::operator!=(const Complex& rhs) const noexcept {
	return re != rhs.re || im != rhs.im;
}

Complex& Complex::operator+=(const Complex& rhs) noexcept { 
	re += rhs.re;
	im += rhs.im;
	return *this; }
Complex& Complex::operator+=(const double rhs) noexcept {
	re += rhs;
	return *this;
}

Complex& Complex::operator-=(const Complex& rhs) noexcept { 
	re -= rhs.re;
	im -= rhs.im;
	return *this; }
Complex& Complex::operator-=(const double rhs) noexcept { 
	re -= rhs;
	return *this; }

//Формула: (a+bi)(c+di) = (ac-bd) + (ad+bc)i
Complex& Complex::operator*=(const Complex& rhs) noexcept {  
	double r1 = re;
	re = re * rhs.re - im * rhs.im;
	im = r1 * rhs.im + im * rhs.re;
	return *this;
	}
Complex& Complex::operator*=(const double rhs) noexcept { 
	re *= rhs;
	im *= rhs;
	return *this; }

//Формула: z1/z2 = a+bi/c+di=(ac+bd)/(c**2+d**2) + (bc-ad)/(c**2+d**2) * i
Complex& Complex::operator/=(const Complex& del) { 
	double re1 = re;
	re = (re * del.re + im * del.im) / (del.re * del.re + del.im * del.im);
	im = (im * del.re - re1 * del.im) / (del.re * del.re + del.im * del.im);
	return *this;}
Complex& Complex::operator/=(const double rhs) { 
	re /= rhs;
	im /= rhs;
	return *this; }

std::ostream & Complex::writeTo(std::ostream & ostrm) const
 {
	 ostrm << lb << re << sep << im << rb;
	 return ostrm;
	}

std::istream& Complex::readFrom(std::istream& istrm)
{
	char leftBrace(0);
	double real(0.0);
	char comma(0);
	double imaganary(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
	if (istrm.good()) {
		if ((Complex::lb == leftBrace) && (Complex::sep == comma)
			&& (Complex::rb == rightBrace)) {
			re = real;
			im = imaganary;

		}
		else {
			istrm.setstate(std::ios_base::failbit);

		}

	}
	return istrm;
}








Complex operator+(const Complex& lhs, const Complex& rhs) noexcept { 
	Complex a = Complex(lhs.re + rhs.re, lhs.im + rhs.im);
	return a; }
Complex operator+(const Complex& lhs, const double rhs) noexcept { 
	Complex a = Complex(lhs.re + rhs, lhs.im);
	return a; }
Complex operator+(const double lhs, const Complex& rhs) noexcept { 
	Complex a = Complex(lhs + rhs.re, rhs.im);
	return a; }

Complex operator-(const Complex& lhs, const Complex& rhs) noexcept { 
	Complex a = Complex(lhs.re - rhs.re, lhs.im - rhs.im);
	return a; }
Complex operator-(const Complex& lhs, const double rhs) noexcept { 
	Complex a = Complex(lhs.re - rhs, lhs.im);
	return a; }
Complex operator-(const double lhs, const Complex& rhs) noexcept { 
	Complex a = Complex(lhs - rhs.re, -1 * rhs.im);
	return a; }

Complex operator*(const Complex& lhs, const Complex& ymn) noexcept { 
	Complex a = Complex(lhs.re * ymn.re - lhs.im * ymn.im, lhs.re * ymn.im + lhs.im * ymn.re);
	return a; }
Complex operator*(const Complex& lhs, const double rhs) noexcept { 
	Complex a = Complex(lhs.re * rhs, lhs.im * rhs);
	return a; }
Complex operator*(const double lhs, const Complex& rhs) noexcept { 
	Complex a = Complex(rhs.re * lhs, rhs.im * lhs);
	return a; }

Complex operator/(const Complex& lhs, const Complex& del) { 
	Complex a = Complex((lhs.re * del.re + lhs.im * del.im) / (del.re * del.re + del.im * del.im), (lhs.im * del.re - lhs.re * del.im) / (del.re * del.re + del.im * del.im));
	return a; }
Complex operator/(const Complex& lhs, const double rhs) { 
	Complex a = Complex(lhs.re / rhs, lhs.im / rhs);
	return a; }
Complex operator/(const double lhs, const Complex& rhs) { 
	Complex a = Complex((lhs * rhs.re) / (rhs.re * rhs.re + rhs.im * rhs.im), (-1 * lhs * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im));
	return a; }
