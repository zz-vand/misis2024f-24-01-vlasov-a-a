#include <vector>
#include <iostream>
int main(){
    std::vector <int> msz;
    std::vector <int> mss;
    int n = 0;
    std::cin >> n;
    int ms[n];
    for (int i = 0; i < n; ++i){
        std::cin >> ms[i];}
    int ms1[n];
    for (int k = n-1; k > -1; --k){
        ms1[n-1-k] = ms[k];}
    for (int i = 0; i < n; ++i){
        if (std::find(std::begin(mss), std::end(mss), ms1[i]) != std::end(mss)){
            continue;}
        else{
            msz.push_back(ms1[i]);
            mss.push_back(ms1[i]);}}
    std::cout << msz.size() << std::endl;
    for (int i = msz.size()-1; i > -1; --i){
        std::cout<< msz[i] << std::endl;}
    }
