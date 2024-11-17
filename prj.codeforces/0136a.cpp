#include <iostream> 
int main(){
    int n= 0;
    std::cin >> n;
    int *ms = new int[n];
    int c = 0;
    for (int i = 0; i<n; i++){
        int a = 0;
        std::cin >> a;
        c+=1;
        ms[a-1] = c;
    }
    for (int i = 0; i<n; i++){
        std::cout << ms[i] << std::endl;
    }
    
}
