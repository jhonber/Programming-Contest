// http://codeforces.com/contest/746/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int a, b, c;
  while (cin >> a >> b >> c) {
    int ans = 0;
    int t = 0;
    while (t <= a) {
      if (2 * t <= b && 4 * t <= c) {
        ans = max(ans, t + 2 * t + 4 * t);
      }
      t ++;
    }

    cout << ans << endl;
  }

  return 0;
}