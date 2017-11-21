// http://codeforces.com/contest/894/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
#ifdef ONLINEJUDGE
  ios_base::sync_with_stdio(0); cin.tie(0);
#endif

  string s;
  while (cin >> s) {
    int n = s.size();

    int ans = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        for (int k = j + 1; k < n; ++k) {
          if (s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q') ans ++;
        }
      }
    }
    cout << ans << endl;
  }

  return 0;
}