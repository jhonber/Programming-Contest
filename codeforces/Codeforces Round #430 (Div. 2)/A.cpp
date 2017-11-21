// http://codeforces.com/contest/842/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) <<  endl;

int main() {
#ifdef ONLINEJUDGE
  ios_base::sync_with_stdio(0); cin.tie(0);
#endif

  long long l, r, x, y, k;
  while (cin >> l >> r >> x >> y >> k) {
    bool ok = false;
    while (x <= y) {
      long long t = x * k;
      if (t >= l && t <= r) {
        ok = true;
        break;
      }

      x ++;
    }

    cout << (ok ? "YES" : "NO") << endl;
  }

  return 0;
}