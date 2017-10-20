// http://codeforces.com/contest/876/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main () {
  int n, a, b, c;
  while (cin >> n >> a >> b >> c) {
    n --;
    int ans = (n ? min(a, b) : n);
    while (n - 1 > 0) {
      if (a < b) {
        ans += min(a, c);
      }
      else {
        ans += min(b, c);
      }
      n --;
    }

    cout << ans << endl;
  }

  return 0;
}