#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

const long double EPS = 1e-9;

int cmp (long double x, long double y = 0, long double tol = EPS) {
  return ( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct chee {
  long double t, v;
  chee() {}
  chee(long double a, long double b) : t (a), v (b) {}
};

long double f (vector<chee> &all, long double x) {
  long double a = 1e100, b = 0;
  for (int i = 0; i < all.size(); ++i) {
    long double d = all[i].v * (x - all[i].t);
    a = min(a, d);
    b = max(b, d);
  }

  return b - a;
}

int main() { IO
  cout << fixed << setprecision(10);
  int n;

  while (cin >> n) {
    if (!n) break;

    vector<chee> all(n);
    long double v, t, maxt = 0;
    for (int i = 0; i < n; ++i) {
      cin >> t >> v;
      all[i] = chee(t, v);
      maxt = max(t, maxt);
    }

    int cnt = 10000;
    long double l = maxt, r = 1e12;
    while (r - l > EPS && cnt --> 0) {
      long double m1 = (2.0 * l + r) / 3.0;
      long double m2 = (l + 2.0 * r) / 3.0;

      if (cmp(m1, m2) == 1) break;
      if (cmp(f(all, m1), f(all, m2)) == -1) r = m2;
      else l = m1;
    }

    cout << f(all, (l + r) / 2.0) << endl;
  }

  return 0;
}
