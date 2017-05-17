// http://codeforces.com/contest/808/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, w;
  while (cin >> n >> w) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    bool ok = true;
    vector<int> fill(n, 0);
    for (int i = 0; i < n; ++i) {
      int m = (v[i] + 1) / 2;
      if (w - m >= 0) {
        w -= m;
        fill[i] += m;
      }
      else {
        ok = false;
      }
    }

    while (w > 0) {
      int ind = 0;
      int best = -1;

      for (int i = 0; i < n; ++i) {
        if (v[i] >= best && fill[i] < v[i]) {
          ind = i;
          best = v[i];
        }
      }

      if (best != -1) {
        fill[ind] ++;
        w --;
      }
      else break;
    }

    if (w > 0) ok = false;

    if (!ok) cout << -1 << endl;
    else {
      for (int i = 0; i < n; ++i) cout << fill[i] << " "; cout << endl;
    }
  }

  return 0;
}