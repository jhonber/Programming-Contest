// http://codeforces.com/contest/813/problem/A

#include<bits/stdc++.h>
using namespace std;

#define d(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

int main() {
  int n, m;
  while (cin >> n) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    int sum = accumulate(v.begin(), v.end(), 0);

    cin >> m;
    bool ok = false;
    for (int i = 0; i < m; ++i) {
      int l, r;
      cin >> l >> r;
      if (!ok && sum <= r) {
        cout << max(l, sum) << endl;
        ok = true;
      }
    }

    if (!ok) cout << -1 << endl;
  }

  return 0;
}