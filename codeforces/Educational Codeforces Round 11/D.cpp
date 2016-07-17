// http://codeforces.com/contest/660/problem/D

#include<bits/stdc++.h>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(null);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

struct P {
  double x, y;
  P() {}
  P(double a, double b): x(a), y(b) {}
};

int main() {
  int n;
  cin >> n;

  vector<P> v(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    v[i] = P(x, y);
  }

  map<pair<double, double>, int> cnt;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      double xm, ym;
      xm = (v[i].x + v[j].x) / 2;
      ym = (v[i].y + v[j].y) / 2;
      cnt[{xm, ym}] ++;
    }
  }

  long long ans = 0;
  for (auto i: cnt) {
    ans += i.second * (i.second - 1);
  }

  cout << ans / 2 << endl;
  return 0;
}