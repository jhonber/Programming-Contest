#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t;
  cin >> t;

  while (t --> 0) {
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      v[i] = {a, i};
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (v[i].second == i) ans ++;
    }

    cout << ans << endl;
  }

  return 0;
}