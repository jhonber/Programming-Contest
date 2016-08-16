// http://codeforces.com/contest/706/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

const double EPS = 1e-9;

double dist (double x1, double y1, double x2, double y2) {
  double a = x2 - x1;
  double b = y2 - y1;
  return sqrt(a * a + b * b);
}

int cmp (long double x, long double y = 0, long double tol = EPS) {
  return ( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int main() {
  int x, y;
  cin >> x >> y;

  int n;
  cin >> n;

  double best = 1e100;
  for (int i = 0; i < n; ++i) {
    int a, b, v;
    cin >> a >> b >> v;

    double d = dist(x, y, a, b);
    double r = d / v;

    if (cmp(r, best) == -1) best = r;
  }

  cout << fixed << setprecision(16) << best << endl;

  return 0;
}