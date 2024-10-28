#include <iostream>
int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int n = 0;
		std::cin >> n;
		int* ms = new int[n];
		for (int i = 0; i < n; i++) {
			std::cin >> ms[i];
		}

		int* ms1 = new int[n];
		int count = 0;
		for (int i = 1; i < n; i+=2) {
				ms1[i] = ms[n - i+1*count];
				count += 1;
		}
		int count1 = 0;
		for (int i = 0; i < n; i += 2) {
			ms1[i] = ms[i - 1 * count1];
			count1 += 1;
		}



		for (int i = 0; i < n; i++) {
			std::cout << ms1[i] << std::endl;
		}
	}
}
