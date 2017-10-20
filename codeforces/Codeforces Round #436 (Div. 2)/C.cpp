// http://codeforces.com/contest/864/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int a, b, f, k;
  while (cin >> a >> b >> f >> k) {
    int ans = 0;
    bool ok = true;
    int cap = b;

    for (int i = 0; i < k && ok; ++i) {
      if (i % 2) {
        if (cap - (a - f) < 0) ok = false;
        cap -= a - f;
        if (cap - f < 0 || i + 1 < k && cap - 2 * f < 0) {
          cap = b;
          ans ++;
          if (cap - f < 0) ok = false;
        }
        cap -= f;
      }
      else {
        if (cap - f < 0) ok = false;
        cap -= f;
        if (cap - (a - f) < 0 || i + 1 < k && cap - 2 * (a - f) < 0) {
          cap = b;
          ans ++;
          if (cap - (a - f) < 0) ok = false;
        }
        cap -= a - f;
      }
    }

    cout << (ok ? ans : -1) << endl;
  }

  return 0;
}