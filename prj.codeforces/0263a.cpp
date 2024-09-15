#include <iostream>
int main(){
    int a[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j =0 ; j < 5; j++)
        {
            std::cin >> a[i][j];
        }
     }
     int c = 0;
     for (int i = 0; i < 5; ++i){
         for (int j = 0; j < 5; ++j){
             if (a[i][j] == 1){
                 if (j == 0){
                     c += 2;}
                 if (j == 1){
                     c += 1;}
                     
                 if (j > 2){
                     c += j-2;}
                 if (i == 0){
                     c += 2;}
                 
                 
                 if (i == 1){
                     c+=1;}
                     
                 if (i > 2){
                     c += i-2;}
         }
         }
    
}
std::cout << c << std::endl;
}
