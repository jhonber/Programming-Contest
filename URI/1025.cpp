#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, m;
  int TC = 1;

  while (cin >> n >> m) {
    if (!n) break;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }

    sort(v.begin(), v.end());
    cout << "CASE# " << TC++ << ":" << endl;
    for (int i = 0; i < m; ++i) {
      int q;
      cin >> q;

      auto ind = lower_bound(v.begin(), v.end(), q);
      if (ind != v.end() && *ind == q) {
        cout << q << " found at " << (ind - v.begin()) + 1 << endl;
      }
      else cout << q << " not found" << endl;
    }
  }

  return 0;
}
