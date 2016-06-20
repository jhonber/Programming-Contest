#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

int main() {
  int t;
  cin >> t;

  while (t --> 0) {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    int diff = INT_MAX;
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
      if (v[i] == m) {
        ans = i + 1;
        break;
      }

      int d = abs(v[i] - m);
      diff = min(diff, d);
    }

    if (ans != INT_MAX) cout << ans << endl;
    else {
      for (int i = 0; i < n; ++i) if (abs(v[i] - m) == diff) {
        ans = i + 1;
        break;
      }
      cout << ans << endl;
    }
  }

  return 0;
}