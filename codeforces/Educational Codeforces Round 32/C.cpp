// http://codeforces.com/contest/888/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string s;
  while (cin >> s) {
    int n = s.size();
    vector<int> v[33];
    for (int i = 0; i < n; ++i) {
      v[s[i] - 'a'].push_back(i);
    }

    int ans = n;
    for (int i = 0; i < 26; ++i) {
      if (v[i].size() == 0) continue;

      int mx = v[i][0] + 1;
      for (int j = 0; j < v[i].size(); ++j) {
        mx = max(v[i][j] - v[i][j - 1], mx);
      }

      int t = v[i].size();
      mx = max(mx, n - v[i][t - 1]);

      if (mx == 0) mx = n;
      ans = min(ans, mx);
    }

    cout << ans << endl;
  }

  return 0;
}