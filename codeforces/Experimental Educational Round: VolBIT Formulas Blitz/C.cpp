// http://codeforces.com/contest/630/problem/C

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  if (n == 1) {
    cout << 2 << endl;
    return 0;
  }

  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    long long p = 1;
    int b = i;
    while (b --> 0) {
      p *= 2LL;
    }
    ans += p;
  }

  cout << ans;
  return 0;
}