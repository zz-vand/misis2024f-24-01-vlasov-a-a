#include <iostream>
#include <vector>
int main(){
    int t = 0;
    std::cin >> t;
    for (int q = 0; q < t; ++q){
        int n = 0;
        int x = 0;
        std::cin >> n >> x;
        std :: vector<int> ms(1000);
        for (int i = 0; i<n; ++i){
            int b = 0;
            std::cin >> b;
            ms[b] = 1;}
        int c = 0;
         for (int i = 1; i < 1000; ++i){
            if (ms[i] == 0 and x == 0){
                std::cout << i-1 << std::endl;
                break;}
            if (ms[i] == 0){
                x -= 1;}
         }
}

}
