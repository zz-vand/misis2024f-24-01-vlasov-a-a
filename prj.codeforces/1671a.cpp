#include <iostream> 
#include <string>
int main() {
    int t = 0;
    std::cin >> t;
    while (t--) {
        std::string s = "";
        std::cin >> s;
        int f = 0;
        if (s.size() < 3 && s != "ab" && s != "ba" && s != "a" && s !="b") {
            f = 1;
        }
        else if (s.size() > 2 && s.find("bab") == std::string::npos && s.find("aba") == std::string::npos && s.substr(0, 2) != "ab" 
            && s.substr(0, 2) != "ba" && s.substr(s.size()-2, 2) != "ab" && s.substr(s.size()-2, 2) != "ba") {
            f = 1;
        }
        if (f == 1) {
            std::cout << "YES" << std::endl;
        }
        else {
            std::cout << "NO" << std::endl;
        }
    }

}



