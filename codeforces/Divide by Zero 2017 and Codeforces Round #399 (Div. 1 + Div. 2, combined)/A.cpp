// http://codeforces.com/contest/768/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  int mx = -1, mm = INT_MAX;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    mx = max(mx, v[i]);
    mm = min(mm, v[i]);
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (mm < v[i] && v[i] < mx) ans ++;
  }

  cout << ans << endl;

  return 0;
}