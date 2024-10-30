#include <iostream>
#include <vector>
int main() {

    int n = 0, k = 0;
    std::cin >> n >> k;
    std::vector <int> ms;
    for (int i = 0; i < n; i++) {
        int a = 0;
        std::cin >> a;
        if (a > 0) {
            ms.push_back(a);
        }
    }


    int c = 0;
    if (ms.size() >= k) {
        c = k;
        for (int i = k; i < ms.size(); i++) {
            if (ms[k - 1] == ms[i]) {
                c += 1;
            }
        }
    }
     else {
            c = ms.size();
        }
    std::cout << c << std::endl;

}
