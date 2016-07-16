// http://codeforces.com/contest/669/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
  int n;
  cin >> n;

  int ans = 0;
  int i = 0;
  while (n > 0) {
    if (i % 2 == 0) n -= 1;
    else n -= 2;
    i ++;
    if (n >= 0) ans ++;
  }

  cout << ans << endl;
  return 0;
}