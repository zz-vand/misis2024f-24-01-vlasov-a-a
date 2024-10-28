#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
 
#define endl '\n'
 
void solve() {
    int n, k;
    std :: cin >> n >> k;
 
    std :: string s;
    std :: cin >> s;
 
    bool f = 1;
 
    while (f) {
 
       f = 0;
 
 
       int cnt0 = 0;
       int cnt1 = 0;
 
       for (int i = k; i < n; i++) {
          if (s[i] == '?' && s[i - k] != '?') s[i] = s[i - k];
       }
      for (int i = n - 1; i >= k; i--) {
          if (s[i] != '?' && s[i - k] == '?') s[i - k] = s[i];
       }
 
       for (int i = 0; i < k; i++) {
          if (s[i] == '1') cnt1++;
          if (s[i] == '0') cnt0++;
 
         if (cnt1 > k / 2 || cnt0 > k / 2) {
             std :: cout << "NO";
             return;
          }
       }
 
       if (cnt1 > k / 2 || cnt0 > k / 2) {
          std :: cout << "NO";
          return;
       }
 
       for (int i = k; i < n; i++) {
          if (s[i] == '1') cnt1++;
          if (s[i] == '0') cnt0++;
 
          if (s[i - k] == '1') cnt1--;
          if (s[i - k] == '0') cnt0--;
 
          if (cnt1 > k / 2 || cnt0 > k / 2) {
             std :: cout << "NO";
             return;
          }
       }
 
       for (int i = 0; i < n; i++) {
          if (s[i] == '?') {
 
             if (i >= k) {
                if (s[i - k] == '1') {
                   cnt1++;
                   s[i] = '1';
                }
                else {
                   s[i] = '0';
                   cnt0++;
                }
                continue;
             }
 
             if (cnt1 < k / 2) {
                cnt1++;
                s[i] = '1';
             }
             else {
               cnt0++;
               s[i] = '0';
             }
             f = 1;
             //break;
          }
 
       }
 
    }
 
 
 
    std :: cout << "YES";
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
        std :: cout << endl;
    }
 
    return 0;
} 
