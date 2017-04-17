// http://codeforces.com/contest/801/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string s;
  while (cin >> s) {
    int ans = 0;
    int n = s.size();
    for (int i = 0; i + 1 < n; ++i) {
      if (s[i] == 'V' && s[i + 1] == 'K') {
        s[i] = s[i + 1] = '*';
        ans ++;
      }
    }

    bool f = false;
    for (int i = 0; i + 1 < n; ++i) {
      if (s[i] == s[i + 1] && s[i] != '*') {
        s[i] = s[i + 1] = '*';
        f = true;
      }
    }

    cout << ans + f << endl;
  }

  return 0;
}