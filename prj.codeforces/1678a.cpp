#include <iostream> 
#include <string>
int main() {
    int t = 0;
    std::cin >> t;
    while (t--) {
        int n = 0;
        int f_odinak = 0;
        int num_0 = 0;
        std::cin >> n;
        int arr[sizeof(n)] = {0};
        for (int i = 0; i < n; i++) {
            int a = 0;
            std::cin >> a;
            arr[i] = a;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    f_odinak = 1;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                num_0 += 1;
            }
        }

        if (num_0 > 0) {
            std::cout << n - num_0 << std::endl;
        }
        else if (num_0 == 0 && f_odinak == 1) {
            std::cout << n << std::endl;
        }
        else {
            std::cout << n + 1 << std::endl;
        }
    }

}



