// http://codeforces.com/contest/818/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<int> v(m);
    for (int i = 0; i < m; ++i) cin >> v[i];

    vector<int> ans(n);

    for (int i = 1; i < m; ++i) {
      int other;
      if (v[i] <= v[i - 1]) other = n - v[i - 1] + v[i];
      else other = v[i] - v[i - 1];

      ans[v[i - 1] - 1] = other;
    }

    for (int i = 0; i < m; ++i) v[i] --;

    bool ok = true;
    for (int i = 0; i + 1 < m; ++i) {
      int next = v[i] + ans[v[i]];
      next %= n;
      if (next != v[i + 1]) {
        ok = false;
        break;
      }
    }

    if (ok) {
      for (int i = 0; i < n; ++i) {
        if (!ans[i]) {
          for (int j = 1; j <= n; ++j) {
            bool f = true;
            for (int k = 0; k < n; ++k) {
              if (j == ans[k]) {
                f = false;
                break;
              }
            }

            if (f) {
              ans[i] = j;
              break;
            }
          }
        }
      }

      set<int> st;
      for (int i = 0; i < n; ++i) st.insert(ans[i]);
      if (st.size() != n) cout << -1 << endl;
      else {
        for (int i = 0; i < n; ++i) cout << ans[i] << " "; cout << endl;
      }
    }
    else {
      cout << -1 << endl;
    }
  }

  return 0;
}