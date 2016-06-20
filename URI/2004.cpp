#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

int main() {
  int t;
  cin >> t;

  while (t --> 0) {
    int n;
    cin >> n;

    vector<int> v[110];
    for (int i = 0; i < n; ++i) {
      int a, b;
      cin >> a >> b;
      v[a].push_back(b);
    }

    int ans = 0;
    for (int i = 0; i < 110; ++i) {
      if (v[i].size() == 0) continue;

      int good = false;
      int mx = 0;
      int mx2 = 0;

      for (int j = 0; j < v[i].size(); ++j) {
        int cur = v[i][j];
        if (cur >= 10 && cur <= 100) {
          mx = max(mx, cur);
          good = true;
        }

        mx2 = max(mx2, cur);
      }

      if (good) ans += mx;
      else ans += mx2;
    }

    cout << ans << endl;
  }

  return 0;
}