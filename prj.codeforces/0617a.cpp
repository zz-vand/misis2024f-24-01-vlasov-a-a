
#include <iostream>
int main(){
    int m = 0;
    std::cin >> m;
    int n = m / 5;
    if (m % 5 > 0){
        n += 1;}
    std::cout << n;
}
