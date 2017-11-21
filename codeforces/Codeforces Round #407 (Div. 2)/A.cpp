// http://codeforces.com/contest/789/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

double calc (double x) {
  double w[] = {0.0, 0.5, 1.0};
  if (x == w[0]) return w[0];
  if (x <= w[1]) return w[1];
  return w[2];
}

int main() {
  int n, k;
  while (cin >> n >> k) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    double ans = 0;
    for (int i = 0; i < n; ++i) {
      double t = v[i] / (k * 2.0);
      double d = t - (int)(t);
      ans += (int)t + calc(d);
    }

    cout << (int)ceil(ans) << endl;
  }

  return 0;
}