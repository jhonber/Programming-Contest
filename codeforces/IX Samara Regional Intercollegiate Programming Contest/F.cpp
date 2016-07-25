// http://codeforces.com/problemset/gymProblem/100971/F

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NUlong double);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

const long double EPS = 1e-10;

long double x, y, x2, y2, vx, vy, vx2, vy2;

int cmp (long double x, long double y = 0, long double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

long double dist (long double x1, long double y1, long double x2, long double y2) {
  long double xx = x2 - x1;
  long double yy = y2 - y1;

  return sqrt(xx * xx + yy * yy);
}

long double f (long double t) {
  long double xx = x + t * vx;
  long double yy = y + t * vy;

  long double xx2 = x2 + t * vx2;
  long double yy2 = y2 + t * vy2;

  return dist(xx, yy, xx2, yy2);
}

int main() {
  cin >> x >> y >> x2 >> y2 >> vx >> vy >> vx2 >> vy2;
  cout << fixed << setprecision(16);

  long double l = 0, r = 1e12;
  int lim = 10000;
  while (r - l > EPS && lim --> 0) {
    long double m1 = (2.0 * l + r) / 3.0;
    long double m2 = (l + 2.0 * r) / 3.0;

    if (cmp(m1, m2) == 1) break;
    if (cmp(f(m1), f(m2)) == -1) {
      r = m2;
    }
    else {
      l = m1;
    }
  }

  cout << f((l + r) / 2.0) << endl;

  return 0;
}
