#include <iostream>
int main() {
	int n, m = 0;
	std::cin >> n >> m;
	int summa = 0;
	int tmp = 1;
	while (m--) {
		int a = 0;
		std::cin >> a;
		if (tmp < a) {
			summa += a - tmp;
			tmp = a;
		}
		else if (tmp > a) {
			summa += n - tmp + a;
			tmp = a;
		}

	}
	std::cout << summa;
}

