#include <iostream> 
int main(){
    int n= 0, k = 0;
    std::cin >> n >> k;
    int *ms = new int[n];
    for (int i = 0; i < n; i++){
        std::cin >> ms[i];
    }
    std::sort(ms, ms+n);
    for (int i = n-1; i >= 0; i--){
        if (k % ms[i] == 0){
            std::cout << k / ms[i];
            break;
        }
        
    }
    
}
