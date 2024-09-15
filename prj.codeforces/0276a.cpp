#include <iostream>
int main(){
    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    int ud[n];
    for (int i = 0; i < n; ++i){
        int f = 0;
        int t = 0;
        std::cin >> f >> t;
        if (t > k){
            ud[i] = f - (t - k);}
        else{
            ud[i] = f;}
        
    }
    int mx = ud[0];
    for (int x = 0; x < n; ++x){
        if (ud[x] > mx){
            mx = ud[x];}}
    std::cout << mx << std::endl;
    
}
