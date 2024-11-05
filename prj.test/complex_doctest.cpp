#include <complex/complex.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

int n = 5; 

TEST_CASE("testing the factorial function") {
	CHECK(Complex() == Complex(0.0, 0.0)); 
	CHECK(Complex(5.0, 6.0) != Complex(4.0, 3.0));
	CHECK(Complex(5.0, 6.0) != Complex(5.0, 3.0));
	CHECK(Complex(5.0, 6.0) != Complex(4.0, 6.0));


	CHECK(Complex(2.0) == Complex(2.0, 0.0));


	CHECK(Complex(2.0, 3.0) + n == Complex(7.0, 3.0));
	CHECK(Complex(2.0, 3.0) + Complex(5.0, 4.0) == Complex(7.0, 7.0));
	CHECK(n + Complex(2.0, 3.0) == Complex(7.0, 3.0));


	CHECK(Complex(2.0, 3.0) - n == Complex(-3.0, 3.0));
	CHECK(Complex(2.0, 3.0) - Complex(1.0, 1.0) == Complex(1.0, 2.0));
	CHECK(n - Complex(2.0, 3.0) == Complex(3.0, -3.0));

	Complex k = Complex(5.0, 5.0);
	k += Complex(1.0, 1.0);
	CHECK(k == Complex(6.0, 6.0));
	k += 1;
	CHECK(k == Complex(7.0, 6.0));
	k -= Complex(1.0, 1.0);
	CHECK(k == Complex(6.0, 5.0));
	k -= 1;
	CHECK(k == Complex(5.0, 5.0));


	CHECK(Complex(2.0, 3.0) * n == Complex(10.0, 15.0));


	//Не понимаю что не так, этот тест работает с теми же числами, что и другой, в котором идет присваивание
	CHECK(Complex(12.0, 4.0) * Complex(-4.0, 8.0) == Complex(-80.0, 80.0));

	//Тест не работает по неизвестной причине, в complex.cpp все одианаково
	Complex k2 = Complex(12.0, 4.0);
	k2 *= Complex(-4.0, 8.0);
	CHECK(k2 == Complex(-80.0, 80.0));

	CHECK(n * Complex(2.0, 3.0) == Complex(10.0, 15.0));


	CHECK(Complex(10.0, 5.0) / n == Complex(2.0, 1.0));
	CHECK(Complex(10.0, 5.0) / Complex(4.0, 2.0) == Complex(2.5, 0.0));
	CHECK(10 / Complex(1.0, 1.0) == Complex(5.0, -5.0));

	Complex k1 = Complex(5.0, 5.0);
	k1 *= 2;
	CHECK(k1 == Complex(10.0, 10.0));
	k1 /= Complex(1.0, 1.0);
	CHECK(k1 == Complex(10.0, 0.0));
	k1 = Complex(5.0, 5.0);
	k1 /= 2;
	CHECK(k1 == Complex(2.5, 2.5));

}
