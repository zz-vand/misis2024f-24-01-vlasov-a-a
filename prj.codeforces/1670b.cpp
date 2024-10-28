#include <bits/stdc++.h>

using namespace std;
#define ll long long int
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    string s, k;
    char ch;
    cin >> s;
    ll sl;
    map < char, int > mp;
    cin >> sl;
    for (int i = 0; i < sl; i++) {

      cin >> ch;
      mp[ch]++;
    }
    ll last_ind = -1, mx = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (last_ind != -1)
        mx = max(mx, last_ind - i);
      if (mp[s[i]] > 0)
        last_ind = i;
    }
    cout << mx << endl;
  }
}
