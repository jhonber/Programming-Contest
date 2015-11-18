// http://codeforces.com/contest/597/problem/A

#include<bits/stdc++.h>
using namespace std;

int main() {
  long long k, a, b;
  cin >> k >> a >> b;

  long long ans = 0;
  if (a >= 0) {
    a = abs(a);
    b = abs(b);
    if (a > 0) ans = (b / k) - ((a - 1) / k);
    else ans = (b / k) + 1;
  }
  else if (b <= 0) {
    a = abs(a);
    b = abs(b);
    if (b > 0) ans = (a / k) - ((b - 1) / k);
    else ans = (a / k) + 1;
  }
  else {
    ans += 1;
    a = abs(a);
    b = abs(b);
    ans += a / k;
    ans += b / k;
  }

  cout << ans;
  return 0;
}