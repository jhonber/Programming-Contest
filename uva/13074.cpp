#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int mcm (int a, int b) {
  return (a * b) / __gcd(a, b);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  while (cin >> n) {
    if (!n) break;

    vector<int> v(n);
    for (auto &i: v) cin >> i;

    vector<set<int>> count(n);
    vector<int> cur(n), next(n);

    for (int i = 1; i <= n; ++i) cur[i - 1] = i;

    vector<int> cycle(n, 0);
    bool found = true;
    while (found) {
      found = false;
      for (int i = 0; i < n; ++i) {
        int t = cur[v[i] - 1];
        next[i] = t;
        if (count[i].count(t) == 0) {
          count[i].insert(t);
          cycle[i] ++;
          found = true;
        }
      }
      cur = next;
    }

    set<int> st(cycle.begin(), cycle.end());
    int ans = 1;
    for (auto i: st) {
      ans = mcm(ans, i);
    }

    cout << ans << endl;
  }

  return 0;
}
