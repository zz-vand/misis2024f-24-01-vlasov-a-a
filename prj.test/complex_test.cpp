#include <complex/complex.hpp>


int main() {
	
	setlocale(LC_ALL, "Russian");



	Complex a(0, 0), b(0, 0);
	std::cin >> a >> b;


	bool sz = (a == b);
	std::cout << a << " = " << b << ": " << sz << std::endl;

	Complex sm = a + b;
	std::cout << sm << std::endl;


	Complex rz = a - b;
	std::cout << rz << std::endl;

	Complex ymn = a * b;
	std::cout << ymn << " - Ymnoshenie" << std::endl;

	Complex delen = a / b;
	std::cout << delen << std::endl;

	return 0;


}
