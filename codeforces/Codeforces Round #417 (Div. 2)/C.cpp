// http://codeforces.com/contest/812/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int price;

bool f (vector<long long> &v, int &s, int x) {
  vector<long long> v2 = v;
  for (int i = 0; i < v.size(); ++i) {
    v2[i] += x * (i + 1LL);
  }

  sort(v2.begin(), v2.end());

  long long tot = v2[0];
  x --;
  price = 0;
  for (int i = 1; i < v2.size() && x > 0; ++i) {
    if (tot + v2[i] <= s) {
      tot += v2[i];
      x --;
    }
    else break;
  }

  price = tot;
  return x == 0;
}

int main() {
  int n, s;
  while (cin >> n >> s) {
    vector<long long> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    long long p;
    int lo = 0;
    int hi = n;

    while (lo < hi) {
      int mid = (lo + hi + 1) / 2;
      if (f(v, s, mid)) {
        lo = mid;
        p = price;
      }
      else {
        hi = mid - 1;
      }
    }

    if (p > s) cout << "0 0" << endl;
    else cout << lo << " " << p << endl;
  }

  return 0;
}