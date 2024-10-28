#include <iostream>
#include <vector>
int main(){
    int t =0;
    std::cin >> t;
    
    for (int i =0; i<t; ++i){
        int n, m, sx, sy, d;
        std::cin >> n >> m >> sx >> sy >> d;
        if ((std::abs(sx-1) + std::abs(sy-1) <= d) || (sx == 1 && sy == 1) || (sx == n && sy == m) || (d > 0 && (sx-1) <= d && (n-sx) <= d) || (d > 0 && (sy-1) <= d && (m-sy) <= d) || (d > 0 && (m - sy) <= d && (n-sx) <= d) || (d > 0 && (sx-1) <= d && (sy-1) <= d)){
            std::cout << -1 << std::endl;}
        else{
            std::cout << n+m-2 << std::endl;}
    }
}
