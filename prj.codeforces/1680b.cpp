#include <iostream>
#include <vector>
#include <string>
int main() {
    int t = 0;
    std::cin >> t;
    while (t--) {
        int n = 0;
        int m = 0;
        std::vector <int> stroki;
        std::vector <int> stolb;
        std::cin >> n >> m;
        for (int i = 0; i < n; i++) {
            std::string s = "";
            std::cin >> s;
            for (int k = 0; k < m; k++) {
                if (s[k] == 'R') {
                    stroki.push_back(i);
                    stolb.push_back(k);
                }
            }
        }

        int minstroki = stroki[0];
        int minstolb = stolb[0];
        for (int i = 0; i < stroki.size(); i++) {
            if (stroki[i] < minstroki) {
                minstroki = stroki[i];
            }
            if (stolb[i] < minstolb) {
                minstolb = stolb[i];
            }
        }

        int f = 0;
        for (int i = 0; i < stroki.size(); i++) {
            if (stroki[i] == minstroki) {
                if (stolb[i] == minstolb) {
                    f = 1;
                    std::cout << "YES" << std::endl;
                    break;
                }
            }
        }
        if (f == 0) {
            std::cout << "NO" <<std::endl;
        }


      }
   }

