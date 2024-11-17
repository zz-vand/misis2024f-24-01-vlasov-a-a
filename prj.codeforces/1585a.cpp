#include <iostream> 
int main() {
    int t = 0;
    std::cin >> t;
    while (t > 0) {
        t -= 1;
        int n = 0;
        std::cin >> n;
        int c = 1;
        int a0 = 0;
        std::cin >> a0;
        if (a0 == 1){
            c += 1;
        }
        
            for (int i = 1; i<n; i++){
                    int a = 0;
                    std::cin >> a;
                    if (c != -1){
                    if (a0 == 1 && a == 1){
                        c += 5;
                        a0 = a;
                    }
                    else if(a0 == 0 && a == 1){
                        c+=1;
                        a0 = a;
                    }
                    else if(a0 == 1 && a == 0){
                        a0 = a;
                    }
                    else if(a0 == 0 && a == 0){
                        c = -1;
                    }
                    
                }
            }
        
        
       std::cout << c << std::endl;
    }

}
