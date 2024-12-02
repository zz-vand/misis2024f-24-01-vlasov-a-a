#include <iostream> 
int main() {
    int t = 0;
    std::cin >> t;
    while (t--) {
        int n = 0;
        std::cin >> n;
        int col_ed = 0;
        int col_ed1 = 0;
        int f = 0;
        int c = 0;
        int count = -1;
        for (int i = 0; i < n; i++) {
            int a = 0;
            std::cin >> a;
            if (a == 1 && f == 0){
                col_ed += 1;
            }
            else if (a == 0) {
                f = 1;
            }
            else if (a == 1 && f == 1) {
                col_ed1 = i+1;
                f = 2;
            }
            else if (a == 0 && f == 1) {
                count = n - 1;
                break;
            }
        }
        if (count == -1 && col_ed1 != 0) {
            count = col_ed1 - col_ed;
        }
        else if (count == -1 && col_ed1 == 0) {
            count = 0;
        }
        std::cout << count << std::endl;
    }

}
