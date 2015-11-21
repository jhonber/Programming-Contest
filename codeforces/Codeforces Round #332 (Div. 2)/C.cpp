// http://codeforces.com/contest/599/problem/C

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(NULL); cin.tie(false);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  vector<int> pre(111111, INT_MAX);
  int mm = INT_MAX;
  for (int i = n - 1; i >= 0; --i) {
    mm = min(mm, v[i]);
    pre[i] = mm;
  }


  int mx = v[0];
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    if (mx <= pre[i]) {
      ans ++;
      mx = v[i];
    }
    else mx = max(mx, v[i]);
  }

  cout << ans + 1;
  return 0;
}