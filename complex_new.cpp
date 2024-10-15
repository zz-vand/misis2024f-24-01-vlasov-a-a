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
	

	//Ввод и вывод 
	std::ostream& write(std::ostream& vyvod) {
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
std::ostream& operator<<(std::ostream is, Complex& vyvod) {
	return vyvod.write(is);
}
std::istream& operator>>(std::istream is, Complex& vvod) {
	return vvod.read(is);
}



int main() {
	Complex n1, n2;

	std::cin >> n1;
	std::cin >> n2;

	Complex sum = n1 + n2;
	std::cout << sum << "\n";

	Complex raz = n1 - n2;
	std::cout << raz << "\n";

	Complex umn = n1 * n2;
	std::cout << umn << "\n";

	Complex del = n1 / n2;
	std::cout << del;

	return 0;
}




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

	std::ostream& write(std::ostream& vyvod);
	std::istream& read(std::istream& vvod);


};
inline std::ostream& operator <<(std::ostream is, Complex& vyvod) {
	return vyvod.write(is);
}
inline std::istream& operator>>(std::istream is, Complex& vvod) {
	return vvod.read(is);
}


//Ввод и вывод 
std::ostream& Complex::write(std::ostream& vyvod) {
	vyvod << "{" << re << "," << im << "}";
	return vyvod;
}
std::istream& Complex::read(std::istream& vvod) {
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


int main() {
	Complex n1, n2;
	std::cin >> n1;
	std::cout << 78;

	return 0;
}






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

	std::ostream& write(std::ostream& vyvod) const {
		vyvod << "(" << re << "+" << im << "i)";
		return vyvod;
	}
	std::istream& read(std::istream& vvod) {
		vvod >> re >> im; 
		return vvod;
	}

};


std::ostream& operator<<(std::ostream& os, const Complex& n) {
	return n.write(os);
}

std::istream& operator>>(std::istream& is, Complex& n) {
	return n.read(is);
}





int main() {
	Complex n1, n2;
	std::cin >> n1;
	std::cout << 78;

	return 0;
}














