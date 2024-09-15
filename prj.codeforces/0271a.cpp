#include <iostream>
#include <string>
 
int main(){
 int m = 0;
 std::cin >> m;
 while (++m < 10000){
     std::string s = std::to_string(m);
     if (s[0] != s[1] && s[0] != s[2] && s[0] != s[3] && s[2] != s[1] && s[3] != s[1] && s[2] != s[3]){
         std::cout << m << std::endl;
         break;
     }
 }
}
