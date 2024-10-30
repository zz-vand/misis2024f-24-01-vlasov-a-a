#include <iostream>
#include <vector>
#include <string>
int main() {

    int n = 0;
    std::string s = "";
    std::cin >> n >> s;
    int count = 0;
    std::string chast = "";
    int x = 0, y = 0;
    if (s[0] == 'U') {
        x = 0;
        y = 1;
        chast = "UP";
    }
    else {
        x = 1;
        y = 0;
        chast = "DOWN";
    }
    for (int i = 1; i < s.length(); i++) {
        int x_tmp = x;
        int y_tmp = y;
        if (s[i] == 'U') {
            y += 1;
        }
        else {
            x += 1;
        }

        if (x_tmp == y_tmp) {
            if ((chast == "DOWN") && y > y_tmp){
                count += 1;
                chast = "UP";
            }
            else if ((chast == "UP") && x > x_tmp) {
                count += 1;
                chast = "DOWN";
            }
        }

    }

    std::cout << count << std::endl;
}

