// http://codeforces.com/contest/466/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  long long n, a, b;
  while (cin >> n >> a >> b) {
    if (a * b >= 6 * n) {
      cout << a * b << endl << a << " " << b << endl;
      continue;
    }

    bool f = false;
    if (a > b) {
      swap(a, b);
      f = true;
    }

    long long x = a, y = b, lim = 6 * n;
    long long ans = LLONG_MAX;
    long long xx, yy;

    for ( ; x * x <= lim; ++x) {
      y = max(lim / x, b);
      if (x * y < lim) y ++;

      if (x * y >= lim && ans > x * y) {
        ans = x * y;
        xx = x;
        yy = y;
      }
    }

    if (f) swap(xx, yy);

    cout << xx * yy << endl << xx << " " << yy << endl;
  }

  return 0;
}