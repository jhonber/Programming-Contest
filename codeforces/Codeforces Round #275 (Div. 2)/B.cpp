// http://codeforces.com/contest/483/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

bool f (long long a, long long b, long long x, long long y, long long l) {
  long long c = l / (x * y);
  long long aa = (l / y) - c;
  long long bb = (l / x) - c;

  long long r = l - (aa + bb + c);

  if (aa >= a && bb >= b) return true;

  if (a - aa > b - bb) {
    if (r >= a - aa) {
      r -= a - aa;
      aa = a;
    }
    if (r >= b - bb) {
      r -= b - bb;
      bb = b;
    }
  }
  else {
    if (r >= b - bb) {
      r -= b - bb;
      bb = b;
    }
    if (r >= a - aa) {
      r -= a - aa;
      aa = a;
    }
  }

  return aa >= a && bb >= b;
}

int main() {
  long long a, b, x, y;
  cin >> a >> b >> x >> y;

  long long lo = 1;
  long long hi = 3 * 1e9;
  long long mid, tot;

  while (lo <= hi) {
    mid = (lo + hi) / 2;

    bool ok = f(a, b, x, y, mid);

    if (!ok) {
      lo = mid + 1;
    }
    else {
      hi = mid - 1;
    }
  }

  if (f(a, b, x, y, mid)) cout << mid << endl;
  else if (f(a, b, x, y, mid + 1)) cout << mid + 1 << endl;
  else assert(false);

  return 0;
}