// http://codeforces.com/contest/765/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int k, a, b;
  cin >> k >> a >> b;

  int aa = a / k;
  int bb = b / k;

  int ans = (a / k) + (b / k);
  if (a % k != 0 && !bb || b % k != 0 && !aa) cout << -1 << endl;
  else cout << ans << endl;

  return 0;
}