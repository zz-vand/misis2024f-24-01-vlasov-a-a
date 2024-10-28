#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
 
#define endl '\n'
 
void solve() {
    int a, b;
    std :: cin >> a >> b;
 
    std :: string s;
    std :: cin >> s;
 
    int n = a + b ;
 
    int l = 0, r = a + b - 1;
 
    while (l < r) {
        if (s[r] == '1') {
            if (s[l] == '0') {
                std :: cout << -1 << endl;
                return;
            }
            b -= 2;
            s[l] = '1';
        }
        else if (s[r] == '0') {
            if (s[l] == '1') {
                std :: cout << -1 << endl;
                return;
            }
            a -= 2;
            s[l] = '0';
        }
        else if (s[l] == '1') {
            if (s[r] == '0') {
               std ::  cout << -1 << endl;
                return;
            }
            b -= 2;
            s[r] = '1';
        }
        else if (s[l] == '0') {
            if (s[r] == '1') {
                std :: cout << -1 << endl;
                return;
            }
            a -= 2;
            s[r] = '0';
        }
        r--;
        l++;
    }
 
    if (a < 0 || b < 0) {
        std :: cout << -1 << endl;
        return;
    }
    l = 0;
    r = n - 1;
 
    while (l < r) {
        if (s[l] == '?') {
            if (a > 1) {
                a -= 2;
                s[l] = '0';
                s[r] = '0';
            }
            else {
                b -= 2;
                s[l] = '1';
                s[r] = '1';
            }
        }
        l++;
        r--;
    }
 
    if (a == 1) {
        if (s[n / 2] == '1') {
            std :: cout << -1 << endl;
            return;
        }
        a--;
        s[(n) / 2] = '0';
    }
    if (b == 1) {
        b--;
        if (s[n / 2] == '0') {
            std :: cout << -1 << endl;
            return;
        }
        s[(n) / 2] = '1';
    }
    if (a < 0 || b < 0) {
        std :: cout << -1 << endl;
        return;
    }
    std :: cout << s << endl;
}
 
signed main()
{
    std :: ios_base::sync_with_stdio(0);
    std :: cin.tie(0);
    std :: cout.tie(0);
 
    int t;
    std :: cin >> t;
 
    while (t > 0) {
        t--;
        solve();
    }
 
    return 0;
}
