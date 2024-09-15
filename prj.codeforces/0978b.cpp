#include <iostream>
#include <string>
#include <vector>
int main(){
    int n = 0;
    std::vector <int> ms;
    std::cin >> n;
    std::string s = "";
    std::cin >> s;
    int tmp = 0;
    for (int i = 0; i < n; ++i){
        if (s[i] == 'x'){
            tmp += 1;
            if (i == n-1){
                ms.push_back(tmp);}}
        else{
            ms.push_back(tmp);
            tmp = 0;}}
    int con = 0;
    for (int i = 0; i < ms.size(); ++i){
       if (ms[i] > 2){
           con += ms[i] - 2;}
           }
    std::cout << con << std::endl;
}
