#include <iostream>
int main(){
	int t = 0;
	std::cin >> t;
	while (t--) {
		int n, m, k;
		std::cin >> n >> m >> k;
		if (n * m - 1 == k) {
			std::cout << "YES" << std::endl;
		}
		else {
			std::cout << "NO" << std::endl;
		}
	}
}
