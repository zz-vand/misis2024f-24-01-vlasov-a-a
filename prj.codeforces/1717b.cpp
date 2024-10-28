#include <iostream>
#include <vector>
using namespace std;
int main(){
    int t = 0;
    cin >> t;
    for (int q = 0; q < t;q++){
        int n, k, r, c;
        cin >> n >> k >> r >> c;
        vector <vector<int>> ms(n+1, vector<int> (n+1));
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if ((i+j) % k == (c + r) % k){
                    ms[i][j] = 1;
                }
                if (ms[i][j] == 0){
                    cout << ".";
                }
                else{
                    cout << "X";
                }
            }
            cout << endl;
        }
    }
}
