// http://codeforces.com/contest/591/problem/A

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(NULL); cin.tie(false);
#define endl "\n"
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  double d1 = 0;
  double d2 = 0;
  double a = 0;
  double b = 10000;

  double l, p, q;
  cin >> l >> p >> q;

  while (true) {
    double c = (a + b) / 2.;
    d1 = c * p;
    d2 = c * q;

    double tmp = d1 + d2;
    if (fabs(tmp - l) < 1e-5) break;
    if (tmp > l) {
      b = c;
    }
    else {
      a = c;
    }
  }

  printf("%.10lf", d1);
  return 0;
}