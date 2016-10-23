// http://codeforces.com/contest/732/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main () {
  int k, r;
  cin >> k >> r;

  int ans = 0;
  int ans2 = -1;
  int i = 1;
  int ok = false;
  while (i < 1000000) {
    int c = (i * k) % 10;
    if (c == r && ((i * k) - c) % 10 == 0) {
      ok = true;
      break;
    }
    if ((i * k) % 10 == 0 && ans2 == -1) ans2 = i;
    i ++;
  }

  if (i == 1000000 && ans2 != -1) cout << ans2 << endl;
  else cout << i << endl;

  return 0;
}