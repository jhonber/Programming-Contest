// http://codeforces.com/contest/796/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, m, k;
  while (cin >> n >> m >> k) {
    int ind = m - 1;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    int ans = INT_MAX;
    int tot = 0;
    for (int i = ind; i < n; ++i) {
      if (v[i] > 0 && v[i] <= k) {
        ans = min(ans, tot);
        break;
      }
      tot += 10;
    }

    tot = 0;
    for (int i = ind; i >= 0; --i) {
      if (v[i] > 0 && v[i] <= k) {
        ans = min(ans, tot);
        break;
      }
      tot += 10;
    }

    cout << ans << endl;
  }

  return 0;
}