// http://codeforces.com/contest/842/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) <<  endl;

double dist (double x1, double y1, double x2, double y2) {
  double a = x2 - x1;
  double b = y2 - y1;
  return sqrt(a * a +  b * b);
}

int main() {
#ifdef ONLINEJUDGE
  ios_base::sync_with_stdio(0); cin.tie(0);
#endif

  double r, d;
  int n;
  while (cin >> r >> d >> n) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      double x, y, ri;
      cin >> x >> y >> ri;
      double dd = dist(0, 0, x, y);
      ans += (dd + ri <= r && dd - ri >= r - d);
    }

    cout << ans << endl;
  }

  return 0;
}