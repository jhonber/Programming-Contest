// http://codeforces.com/contest/588/problem/C

#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;


int main() { IO
  const int mx = 1200000;
  int bits[mx];

  memset(bits, 0, sizeof bits);

  int n, w;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> w;
    bits[w] ++;
  }

  int ans = 0;
  for (int i = 0; i + 1 < mx; ++i) {
    bits[i + 1] += bits[i] / 2;
    bits[i] %= 2;
    ans += bits[i];
  }

  cout << ans;
  return 0;
}