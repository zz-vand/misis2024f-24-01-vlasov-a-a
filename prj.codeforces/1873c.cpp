#include <iostream>
int main() {
	int t = 0;
	std::cin >> t;
	while(t--){
		int summa = 0;
		char s;
		int col = 0;
		int stroki = 1;
		for (int i = 0; i < 100; i++) {
			std::cin >> s;
			col += 1;
			if (col == 11) {
				col = 1;
				stroki += 1;
			}
			if (s == 'X') {
				if (stroki == 1 || stroki == 10) {
					summa += 1;
				}
				else if (stroki == 2 || stroki == 9) {
					if (col > 1 && col < 10) {
						summa += 2;
					}
					else {
						summa += 1;
					}
				}
				else if (stroki == 3 || stroki == 8) {
					if (col == 1 || col == 10) {
						summa += 1;
					}
					else if (col == 2 || col == 9) {
						summa += 2;
					}
					else {
						summa += 3;
					}
				}

				else if (stroki == 4 || stroki == 7) {
					if (col == 1 || col == 10) {
						summa += 1;
					}
					else if (col == 2 || col == 9) {
						summa += 2;
					}
					else if (col == 3 || col == 8) {
						summa += 3;
					}
					else {
						summa += 4;
					}
				}
				else if (stroki == 5 || stroki == 6) {
					if (col == 1 || col == 10) {
						summa += 1;
					}
					else if (col == 2 || col == 9) {
						summa += 2;
					}
					else if (col == 3 || col == 8) {
						summa += 3;
					}
					else if (col == 4 || col == 7) {
						summa += 4;
					}
					else {
						summa += 5;
					}
				}

			}
			
		}
		std::cout << summa << std::endl;
	}
} 
