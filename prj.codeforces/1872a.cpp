#include <iostream>
#include <cmath>
int main(){
    int t = 0;
    std::cin >> t;
    for (int i = 0; i < t; ++i){
        int a = 0, b =0, c= 0;
        std::cin >> a >> b >> c;
        int rz = abs(a - b);
        int s = rz / (c*2);
        if ((rz % (c*2)) != 0){
            s+=1;}
        std::cout << s << std::endl;
        
        
 
    }
    
}
