#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios::sync_with_stdio(false); cin.tie(NULL);

const double EPS = 1e-6;

double f (double m, vector<long long> &v) {
  double r = 0;
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] - m >= 0) {
      r += v[i] - m;
    }
    else break;
  }

  return r;
}

int main() { IO
  int n;
  long long a;

  cout << fixed << setprecision(4);

  while (cin >> n >> a) {
    if (!n) break;

    vector<long long> v(n);
    double ans = 0;

    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      ans += v[i];
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    if (ans == a) {
      cout << ":D" << endl;
      continue;
    }

    if (ans < a) {
      cout << "-.-" << endl;
      continue;
    }

    double mid, l = 0, r = v[0];

    while (l != r) {
      mid = (l + r) / 2;

      ans = f(mid, v);

      if (fabs(ans - a) < EPS) break;

      if (ans >= a) {
        l = mid;
      }
      else {
        r = mid;
      }
    }

    cout << mid << endl;
  }

  return 0;
}