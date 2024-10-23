
#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <iosfwd>


struct Complex {
	double re = 0.0;
	double im = 0.0;

	//! \brief Умолчательный конструктор.
	Complex() = default;

	//! \brief Копирующий конструктор.
	Complex(const Complex&) = default;

	Complex(Complex&&) = default;

	//! \brief Конструирование комплексного числа из заданного вещественного.
	//! \param real - вещественная часть комплексного числа
	explicit Complex(const double real) : re(real) { }

	//! \brief Конструирование комплексного числа
	//!
	//! с заданными вещественной real и мнимой imaginary частями.
	//! \param[in] real - вещественная часть комплексного числа
	//! \param[in] imaginary - мнимая часть комплексного числа
	Complex(const double real, const double imaginary) : re(real), im(imaginary) {}
	//Информация
	std::string text = "Комплексные числа — это числа вида a + bi, где a и b — вещественные числа, а i — мнимая единица, то есть число, для которого выполняется равенство: i^2 = -1.\n"
		"Любое комплексное число z = a + bi включает в состав пару компонентов : a — вещественная составляющая числа z, b — мнимый компонент числа z.\n"
		"Множество комплексных чисел обычно обозначается символом C.\n"
		"Уникальные свойства комплексных чисел и функций нашли широкое применение для решения многих практических задач в различных областях математики, физики и техники :\n"
		"в обработке сигналов, теории управления, электромагнетизме, теории колебаний, теории упругости и многих других.\n";
	std::string info() {
		return text;
	}




	//Присваивание.
	Complex& operator=(const Complex&) = default;

	Complex& operator=(Complex&&) = default;



	//Унарный минус
	Complex operator-() const noexcept;

	//Равенство
	[[nodiscard]] bool operator==(const Complex& rhs) const noexcept;

	//Неравенство
	[[nodiscard]] bool operator!=(const Complex& rhs) const noexcept;

	//Присваивающее сложение с комплексным числом.
	Complex& operator+=(const Complex& rhs) noexcept;

	//Присваивающее сложение с double числом.
	Complex& operator+=(const double rhs) noexcept;

	//Присваивающее вычитание комплексного числа.
	Complex& operator-=(const Complex& rhs) noexcept;

	//Присваивающее вычитание double числа.
	Complex& operator-=(const double rhs) noexcept;

	// Присваивающее умножение на комплексное число.
	Complex& operator*=(const Complex& rhs) noexcept;

	//Присваивающее умножение на double число.
	Complex& operator*=(const double rhs) noexcept;

	//Присваивающее деление на комплексное число.
	//Осуществляется путем домножения числителя и знаменателя на комплексно сопряженное с rhs.
	Complex& operator/=(const Complex& rhs);

	//Присваивающее деление на double число.
	Complex& operator/=(const double rhs);

	//Форматированный вывод в поток ostrm комплексного числа в виде {re,im}.
	[[nodiscard]] std::ostream& WriteTo(std::ostream& ostrm) const noexcept;

	//Форматированный ввод из потока istrm комплексного числа в виде {re,im}.
	[[nodiscard]] std::istream& ReadFrom(std::istream& istrm) noexcept;



	static const char leftBrace{ '{' };   //!< левая скобка форматированного представления
	static const char separator{ ',' };   //!< разделитель форматированного представления
	static const char rightBrace{ '}' };  //!< правая скобка форматированного представления
};

//Сложение и вычитание комплексных чисел.
[[nodiscard]] Complex operator+(const Complex& lhs, const Complex& rhs) noexcept;
[[nodiscard]] Complex operator-(const Complex& lhs, const Complex& rhs) noexcept;

//Сложение и вычитание комплексного и double чисел.
[[nodiscard]] Complex operator+(const Complex& lhs, const double rhs) noexcept;
[[nodiscard]] Complex operator-(const Complex& lhs, const double rhs) noexcept;

//Сложение и вычитание double и комплексного чисел.
[[nodiscard]] Complex operator+(const double lhs, const Complex& rhs) noexcept;
[[nodiscard]] Complex operator-(const double lhs, const Complex& rhs) noexcept;

//Умножение комплексного числа на комплексное.
[[nodiscard]] Complex operator*(const Complex& lhs, const Complex& rhs) noexcept;

//Умножение комплексного числа на вещественное.
[[nodiscard]] Complex operator*(const Complex& lhs, const double rhs) noexcept;

//Умножение вещественного числа на комплексное.
[[nodiscard]] Complex operator*(const double lhs, const Complex& rhs) noexcept;

//Деление комплексного числа на комплексное.
[[nodiscard]] Complex operator/(const Complex& lhs, const Complex& rhs);

//Деление комплексного числа на вещественное.
[[nodiscard]] Complex operator/(const Complex& lhs, const double rhs);

//Деление вещественного числа на комплексное.
[[nodiscard]] Complex operator/(const double lhs, const Complex& rhs);

//Форматированный вввод в потока ostrm комплексного числа \se Complex::write_to.
inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) noexcept {
	return rhs.WriteTo(ostrm);
}

//Форматированный ввод из потока istrm комплексного числа \se Complex::read_from.
inline std::istream& operator>>(std::istream& istrm, Complex& rhs) noexcept {
	return rhs.ReadFrom(istrm);
}

#endif
