#include <iostream>
#include <vector>
#include <string>
int main() {
    int t = 0;
    std::cin >> t;
    while (t--) {
        int arr[8][8] = { 0 };
        for (int i = 0; i < 8; i++) {
            std::string s = "";
            std::cin >> s;
            for (int j = 0; j < 8; j++) {
                if (s[j] == '#') {
                    arr[i][j] = 1;
                }
            }
        }
        for (int i = 1; i < 7; i++) {
            for (int j = 1; j < 7; j++) {
                if (arr[i][j] == 1) {
                    if ((arr[i - 1][j - 1] == 1) && (arr[i - 1][j + 1] == 1) && (arr[i + 1][j - 1] == 1) && (arr[i + 1][j + 1] == 1)) {
                        std::cout << i+1 << " " << j+1 << std::endl;
                        break;
                    }
                }
            }
        }
    }
}
 
 
