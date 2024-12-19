#include <iostream>
#include <vector>
#include <string>
int main() {
    int t = 0;
    std::cin >> t;
    while (t--) {
        int sm = 0;
        for (int i = 0; i < 4; i++) {
            int a = 0;
            std::cin >> a;
            sm += a;
        }
        if (sm == 0) {
            std::cout << 0 << std::endl;
        }
        else if (sm >= 1 && sm <= 3) {
            std::cout << 1 << std::endl;
        }
        else {
            std::cout << 2 << std::endl;
        }
    }
}


