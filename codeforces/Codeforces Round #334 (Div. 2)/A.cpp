// http://codeforces.com/contest/604/problem/A

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(NULL); cie.tie(false);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

double f (double x, double m, double w) {
  double a = .3 * x;
  double b = (1 - (m / 250)) * x - (50 * w);
  return max(a, b);
}

int main() {
  double a,b,c,d,e;
  cin >> a >> b >> c >> d >> e;

  double a2,b2,c2,d2,e2;
  cin >> a2 >> b2 >> c2 >> d2 >> e2;

  double a3, b3;
  cin >> a3 >> b3;

  double ans = (100 * a3) - (50 * b3);
  ans += f (500, a, a2);
  ans += f (1000, b, b2);
  ans += f (1500, c, c2);
  ans += f (2000, d, d2);
  ans += f (2500, e, e2);

  cout << ans;
  return 0;
}