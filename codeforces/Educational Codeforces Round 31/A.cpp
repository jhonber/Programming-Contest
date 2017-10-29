// http://codeforces.com/contest/884/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

const int MX = 86400;

int main() {
  int n, t;
  while (cin >> n >> t) {
    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      t -= MX - x;
      if (t <= 0) ans = min(ans, i + 1);
    }

    cout << ans << endl;
  }

  return 0;
}