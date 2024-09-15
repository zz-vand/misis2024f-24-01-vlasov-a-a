#include <iostream>
#include <cmath>
int main(){
    int t = 0;
    std::cin >> t;
    for (int i = 0; i < t; ++i){
        int m = 0;
        std::cin >> m;
        int m1 = m;
        int con = 0;
        while ( m > 0){
            int s = m%10;
            if (s > 0){
                con+=1;}
            m /= 10;
        }
        std::cout << con << std::endl;
        
        int con_0 = 0;
        while ( m1 > 0){
            int s = m1%10;
            if (s > 0){
                std::cout << s*(pow(10, con_0)) << std::endl;
                con_0+=1;}
            else{
                con_0+=1;}
            m1/=10;
                
        }
        
    }
    
}
