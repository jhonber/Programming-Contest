// http://codeforces.com/contest/782/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

typedef long double ld;

const ld EPS = 1e-9;

int cmp (ld x, ld y = 0, ld tol = EPS) {
  return ( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

bool f (ld t, vector<ld> &friends, vector<ld> &speed) {
  ld L = -1, R = 1e100;

  for (int i = 0; i < friends.size(); ++i) {
    ld d = t * speed[i];
    ld l = friends[i] - d;
    ld r = friends[i] + d;

    if (cmp(l, 0) < 0) l = 0;

    if (cmp(l, L) > 0) L = l;
    if (cmp(r, R) < 0) R = r;
  }

  return L <= R;
}

int main() {
  int n;
  cin >> n;

  vector<ld> friends(n), speed(n);
  for (int i = 0; i < n; ++i) cin >> friends[i];
  for (int i = 0; i < n; ++i) cin >> speed[i];

  ld lo = 0;
  ld hi = 1e100;
  ld mid;

  while (cmp(lo, hi) < 0) {
    mid = (lo + hi) / 2;

    if (f(mid, friends, speed)) {
      hi = mid;
    }
    else {
      lo = mid;
    }
  }

  cout << fixed << setprecision(20);
  cout << hi << endl;

  return 0;
}