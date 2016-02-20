// http://codeforces.com/contest/628/problem/A

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);

int main () {
  int n, b, p;
  cin >> n >> b >> p;

  int ans = 0;
  int ans2 = p * n;

  while (n > 1) {
    ans += 2 * b + 1;
    n --;
  }

  cout << ans << " " << ans2;
  return 0;
}