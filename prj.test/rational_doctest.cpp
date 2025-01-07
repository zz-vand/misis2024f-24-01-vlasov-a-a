#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <rational/rational.hpp>

#include <sstream>

TEST_CASE("[rational] - Rational ctor") {
    CHECK(Rational() == Rational(0, 1));
    CHECK(Rational(3) == Rational(3, 1));
    CHECK(Rational(-3) == Rational(-3, 1));
    CHECK(Rational(10, 6) == Rational(5, 3));
    CHECK(Rational(-10, 6) == Rational(-5, 3));
    CHECK(Rational(10, -6) == Rational(-5, 3));
    CHECK(Rational(-10, -6) == Rational(5, 3));
    CHECK_THROWS(Rational(1, 0));
}

TEST_CASE("[rational] - Rational add") {
    CHECK(Rational(5, 3) + Rational(5, 4) == Rational(35, 12));
    CHECK(Rational(5, 3) + Rational(4, 3) == Rational(3, 1));
    CHECK(Rational() + Rational() == Rational());
    CHECK(Rational() + Rational(3, 5) == Rational(3, 5));
}

TEST_CASE("[rational] - Rational subtract") {
    CHECK(Rational(5, 3) - Rational(5, 4) == Rational(5, 12));
    CHECK(Rational(5, 4) - Rational(5, 3) == Rational(-5, 12));
    CHECK(Rational() - Rational() == Rational());
    CHECK(Rational() - Rational(3, 5) == Rational(-3, 5));
}

TEST_CASE("[rational] - Rational division") {
    CHECK(Rational(5, 2) / Rational(5, 2) == Rational(1, 1));
    CHECK(Rational(5, 2) / Rational(10, 2) == Rational(1, 2));
    CHECK_THROWS(Rational(5, 3) / Rational(0, 3));
}

TEST_CASE("[rational] - Rational minus") {
    CHECK(Rational(-5, 3) == -Rational(5, 3));
    CHECK(Rational(5, 3) == -Rational(-5, 3));
    CHECK(Rational(5, 3) == -(-(Rational(5, 3))));
}

TEST_CASE("[rational] - mixed arithmetic") {
    CHECK(Rational(5, 3) + 1 == Rational(8, 3));
    CHECK(Rational(5, 3) - 1 == Rational(2, 3));
    CHECK(Rational(5, 3) - 2 == Rational(-1, 3));
    CHECK(Rational(5, 3) / 5 == Rational(1, 3));
    CHECK(Rational(5, 3) * 3 == Rational(5, 1));
    CHECK(3 - Rational(2, 1) == Rational(1, 1));
    CHECK(3 * Rational(2, 3) == Rational(2, 1));
    CHECK(3 / Rational(2, 1) == Rational(3, 2));
}
