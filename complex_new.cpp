#include <iostream>
#include <sstream>

struct Complex {

	double re = 0.0;
	double im = 0.0;

	Complex() = default;
	Complex(double re_, double im_) {
		re = re_;
		im = im_;
	}

	//Равенство и неравенство комплексных чисел
	bool operator==(const Complex& n) {
		return (re == n.re) && (im == n.im);
	}
	bool operator!=(const Complex& n) {
		return (re != n.re) || (im != n.im);
	}


	//Сложение комплексных чисел
	//Постфиксный оператор
	Complex operator+(const Complex& slag) {
		Complex a = Complex(re + slag.re, im + slag.im);
		return a;
	}
	//Префиксный оператор
	Complex& operator+=(const Complex slag) {
		re += slag.re;
		im += slag.im;
		return *this;
	}

	//Вычитание комплексных чисел
	//Постфиксный оператор
	Complex operator-(const Complex& vich) {
		Complex a = Complex(re - vich.re, im - vich.im);
		return a;
	}

	//Префиксный оператор
	Complex& operator-=(const Complex& vich) {
		re -= vich.re;
		im -= vich.im;
		return *this;
	}

	//Умножение комплексных чисел
	//Формула: (a+bi)(c+di) = (ac-bd) + (ad+bc)i

	//Постфиксный оператор
	Complex operator*(const Complex& ymn) {
		Complex a = Complex(re * ymn.re - im * ymn.im, re * ymn.im + im * ymn.re);
		return a;
	}
	//Префиксный оператор
	Complex& operator*=(const Complex& ymn) {
		re = re * ymn.re - im * ymn.im;
		im = re * ymn.im + im * ymn.re;
		return *this;
	}


	//Деление комплексных чисел 
	//Формула: z1/z2 = a+bi/c+di=(ac+bd)/(c**2+d**2) + (bc-ad)/(c**2+d**2) * i

	//Постфиксный оператор
	Complex operator/(const Complex& del) {
		Complex a = Complex((re * del.re + im * del.im) / (del.re * del.re + del.im * del.im), (im * del.re - re * del.im) / (del.re * del.re + del.im * del.im));
		return a;
	}

	//Префиксный оператор
	Complex& operator/=(const Complex& del) {
		re = (re * del.re + im * del.im) / (del.re * del.re + del.im * del.im);
		im = (im * del.re - re * del.im) / (del.re * del.re + del.im * del.im);
		return *this;
	}

	std::ostream& write(std::ostream& vyvod){
		vyvod << "{" << re << "," << im << "}";
		return vyvod;
	}
	std::istream& read(std::istream& vvod) {
		char lb = 0;
		double real = 0.0;
		double image = 0.0;
		char comma = 0;
		char rb = 0;
		vvod >> lb >> real >> comma >> image >> rb;
		if (vvod.good()) {
			if (lb == '{' && rb == '}' && comma == ',') {
				re = real;
				im = image;
			}
			else {
				vvod.setstate(std::ios_base::failbit);
			}
		}
		return vvod;
	}
};


std::ostream& operator<<(std::ostream& is, Complex& vyvod) {
	return vyvod.write(is);
}

std::istream& operator>>(std::istream& is, Complex& vvod) {
	return vvod.read(is);
}



int main() {
	Complex a(0,0), b(0,0);
	std::cin >> a >> b;

	Complex sm = a + b;
	std::cout << sm << std::endl;


	Complex rz = a - b;
	std::cout << rz << std::endl;

	Complex ymn = a * b;
	std::cout << ymn << std::endl;

	Complex delen = a / b;
	std::cout << delen << std::endl;

	return 0;

}
