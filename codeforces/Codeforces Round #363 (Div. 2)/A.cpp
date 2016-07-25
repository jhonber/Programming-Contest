// http://codeforces.com/contest/699/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  string dir;
  cin >> dir;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  int ans = INT_MAX;
  for (int i = 1; i < dir.size(); ++i) {
    if (dir[i - 1] == 'R' && dir[i] == 'L') {
      int d = (v[i] - v[i - 1]) / 2;
      ans = min(ans, d);
    }
  }

  if (ans == INT_MAX) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}