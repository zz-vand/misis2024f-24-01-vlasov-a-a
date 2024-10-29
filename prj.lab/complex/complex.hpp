#ifndef COMPLEX_COMPLEX_H
#define COMPLEX_COMPLEX_H

#include <iosfwd>


struct Complex {
	
  double re{ 0.0 };   //вещественная часть комплексного числа
  double im{ 0.0 };   //мнимая часть комплексного числа

  static const char leftBrace{ '{' };   // левая скобка 
  static const char separator{ ',' };   // разделитель
  static const char rightBrace{ '}' };  // правая скобка 
	
  Complex() = default;


  Complex(const Complex&) = default;

  Complex(Complex&&) = default;

  explicit Complex(const double real) : re(real) { }


  Complex(const double real, const double imaginary) {
	  re = real;
	  im = imaginary;
  }

  Complex& operator=(const Complex&) = default;

  Complex& operator=(Complex&&) = default;


  ~Complex() = default;


  //Унарный минус
  [[nodiscard]] Complex operator-() const noexcept;

  //Унарный плюс
  [[nodiscard]] Complex operator+() const noexcept;

  //Равенство комплексных чисел
  [[nodiscard]] bool operator==(const Complex& rhs) const noexcept;

  //Неравенство комплексных чисел
  [[nodiscard]] bool operator!=(const Complex& rhs) const noexcept;

  // Присваивающее сложение с комплексным числом.
  Complex& operator+=(const Complex& rhs) noexcept;

  //Присваивающее сложение с вещественным числом.
  Complex& operator+=(const double rhs) noexcept;

  //Присваивающее вычитание комплексного числа.
  Complex& operator-=(const Complex& rhs) noexcept;

  //Присваивающее вычитание вещественного числа.
  Complex& operator-=(const double rhs) noexcept;

  //Присваивающее умножение на комплексное число.
  //Формула: (a+bi)(c+di) = (ac-bd) + (ad+bc)i
  Complex& operator*=(const Complex& rhs) noexcept;

  //Присваивающее умножение на вещественное число.
  Complex& operator*=(const double rhs) noexcept;

  //Присваивающее деление на комплексное число.
  //Формула: z1/z2 = a+bi/c+di=(ac+bd)/(c**2+d**2) + (bc-ad)/(c**2+d**2) * i
  Complex& operator/=(const Complex& rhs);

  // Присваивающее деление на вещественное число.
  Complex& operator/=(const double rhs);

  //Форматированный вывод в поток ostrm комплексного числа в виде {re,im}.
  [[nodiscard]] std::ostream& WriteTo(std::ostream& ostrm) const noexcept;

  //Форматированный ввод из потока istrm комплексного числа в виде {re,im}.
  [[nodiscard]] std::istream& ReadFrom(std::istream& istrm) noexcept;

 

 
};

//Сложение комплексных чисел.
[[nodiscard]] Complex operator+(const Complex& lhs, const Complex& rhs) noexcept;

// Сложение комплексного и вещественного чисел.
[[nodiscard]] Complex operator+(const Complex& lhs, const double rhs) noexcept;

//Сложение вещественного и комплексного чисел.
[[nodiscard]] Complex operator+(const double lhs, const Complex& rhs) noexcept;

[[nodiscard]] Complex operator-(const Complex& lhs, const Complex& rhs) noexcept;
[[nodiscard]] Complex operator-(const Complex& lhs, const double rhs) noexcept;
[[nodiscard]] Complex operator-(const double lhs, const Complex& rhs) noexcept;

//Умножение комплексного числа на комплексное.
[[nodiscard]] Complex operator*(const Complex& lhs, const Complex& rhs) noexcept;

//Умножение комплексного числа на вещественное.
[[nodiscard]] Complex operator*(const Complex& lhs, const double rhs) noexcept;

//Умножение вещественного числа на комплексное.
[[nodiscard]] Complex operator*(const double lhs, const Complex& rhs) noexcept;

//Деление комплексного числа на комплексное.
[[nodiscard]] Complex operator/(const Complex& lhs, const Complex& rhs);

// Деление комплексного числа на вещественное.
[[nodiscard]] Complex operator/(const Complex& lhs, const double rhs);

// Деление вещественного числа на комплексное.
[[nodiscard]] Complex operator/(const double lhs, const Complex& rhs);

//Форматированный вввод в поток ostrm комплексного числа \se Complex::write_to.
inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) noexcept {
  return rhs.WriteTo(ostrm);
}

//Форматированный ввод из потока istrm комплексного числа \se Complex::read_from.
inline std::istream& operator>>(std::istream& istrm, Complex& rhs) noexcept {
  return rhs.ReadFrom(istrm);
}

#endif
