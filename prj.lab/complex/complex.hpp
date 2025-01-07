#ifndef COMPLEX_COMPLEX_H
#define COMPLEX_COMPLEX_H

#include <iosfwd>
#include <string>
#include <istream>
#include <ostream>
#include <iostream>


struct Complex {
	
  double re{ 0.0 };   //вещественная часть комплексного числа
  double im{ 0.0 };   //мнимая часть комплексного числа

  static const char lb{ '{' };   // левая скобка 
  static const char sep{ ',' };   // разделитель
  static const char rb{ '}' };  // правая скобка 
	
  Complex() = default;


  Complex(const Complex&) = default;

  Complex(Complex&&) = default;

  explicit Complex(const double real) : re(real) { }


  Complex(const double real, const double imaginary) {
	  re = real;
	  im = imaginary;
  }

  std::string text = "Комплексные числа — это числа вида a + bi, где a и b — вещественные числа, а i — мнимая единица, то есть число, для которого выполняется равенство: i^2 = -1.\n"
	  "Любое комплексное число z = a + bi включает в состав пару компонентов : a — вещественная составляющая числа z, b — мнимый компонент числа z.\n"
	  "Множество комплексных чисел обычно обозначается символом C.\n"
	  "Уникальные свойства комплексных чисел и функций нашли широкое применение для решения многих практических задач в различных областях математики, физики и техники :\n"
	  "в обработке сигналов, теории управления, электромагнетизме, теории колебаний, теории упругости и многих других.\n";
  std::string info() {
	  return text;
  }




  Complex& operator=(const Complex&) = default;

  Complex& operator=(Complex&&) = default;


  ~Complex() = default;


  //Унарный минус
   Complex operator-() const noexcept;

  //Унарный плюс
   Complex operator+() const noexcept;

  //Равенство комплексных чисел
   bool operator==(const Complex& rhs) const noexcept;

  //Неравенство комплексных чисел
   bool operator!=(const Complex& rhs) const noexcept;

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

  std::ostream& writeTo(std::ostream& ostrm) const;
  std::istream & readFrom(std::istream & istrm);
};

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
	return rhs.writeTo(ostrm);
	}
 inline std::istream & operator>>(std::istream & istrm, Complex & rhs)
{
	return rhs.readFrom(istrm);
	}






//Сложение комплексных чисел.
 Complex operator+(const Complex& lhs, const Complex& rhs) noexcept;

// Сложение комплексного и вещественного чисел.
 Complex operator+(const Complex& lhs, const double rhs) noexcept;

//Сложение вещественного и комплексного чисел.
 Complex operator+(const double lhs, const Complex& rhs) noexcept;

 Complex operator-(const Complex& lhs, const Complex& rhs) noexcept;
 Complex operator-(const Complex& lhs, const double rhs) noexcept;
 Complex operator-(const double lhs, const Complex& rhs) noexcept;

//Умножение комплексного числа на комплексное.
 Complex operator*(const Complex& lhs, const Complex& rhs) noexcept;

//Умножение комплексного числа на вещественное.
 Complex operator*(const Complex& lhs, const double rhs) noexcept;

//Умножение вещественного числа на комплексное.
 Complex operator*(const double lhs, const Complex& rhs) noexcept;

//Деление комплексного числа на комплексное.
 Complex operator/(const Complex& lhs, const Complex& rhs);

// Деление комплексного числа на вещественное.
 Complex operator/(const Complex& lhs, const double rhs);

// Деление вещественного числа на комплексное.
 Complex operator/(const double lhs, const Complex& rhs);




#endif
