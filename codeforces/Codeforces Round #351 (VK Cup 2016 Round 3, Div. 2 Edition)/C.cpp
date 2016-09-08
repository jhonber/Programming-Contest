// http://codeforces.com/contest/673/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  vector<int> cnt(5555, 0);
  vector<int> ans(5555, 0);
  for (int i = 0; i < n; ++i) {
    int ind = 5555;
    int mx = -1;

    for (int j = i; j < n; ++j) {
      cnt[v[j]] ++;
      int val = cnt[v[j]];
      if (val > mx) {
        mx = val;
        ind = v[j];
      }

      if (val == mx) {
        ind = min(ind, v[j]);
      }

      ans[ind - 1] ++;
    }

    for (int j = 1; j <= n; ++j) cnt[j] = 0;
  }

  for (int i = 0; i < n; ++i) cout << ans[i] << " ";

  return 0;
}