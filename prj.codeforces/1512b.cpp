#include <iostream> 
int main() {
    int t = 0;
    std::cin >> t;
    while (t > 0) {
        t -= 1;
        int n = 0;
        std::cin >> n;
        int xa = 0, ya = 0;
        int xb = 0, yb = 0;
        int cx = 0, cy = 1;
        int z = 1;
        for (int i = 0; i < n * n; i++) {
            cx += 1;
            if (cx == n + 1) {
                cx = 1;
                cy += 1;
            }
            char a;
            std::cin >> a;
            if (a == '*' and z == 1) {
                xa = cx;
                ya = cy;
                z = 2;
            }
            else if (a == '*' and z == 2) {
                xb = cx;
                yb = cy;
            }
        }

        int xa1 = 0, ya1 = 0;
        int xb1 = 0, yb1 = 0;

        if (xa == xb) {
            if (xa != n){
            xa1 = xa + 1;
            xb1 = xb + 1;
            ya1 = ya;
            yb1 = yb;
            }
            else{
            xa1 = xa - 1;
            xb1 = xb - 1;
            ya1 = ya;
            yb1 = yb; 
            }
        }
        else if (ya == yb)
        {
        if (ya != n){
            xa1 = xa;
            xb1 = xb;
            ya1 = ya+1;
            yb1 = yb+1;
            }
            else{
            xa1 = xa;
            xb1 = xb;
            ya1 = ya-1;
            yb1 = yb-1; 
            }
        }

        else {
            xa1 = xa;
            ya1 = yb;
            xb1 = xb;
            yb1 = ya;

        }
        
        for (int j = 1; j<=n; j++){
            for (int i = 1; i<=n; i++){
                if ((i == xa && j == ya) || (i == xb && j == yb) || (i == xa1 && j == ya1) || (i == xb1 && j == yb1)){
                    std::cout << "*";
                }
                else{
                    std::cout << ".";
                }
            }
            std::cout << "" << std::endl;
        }
        
        

    }

}
