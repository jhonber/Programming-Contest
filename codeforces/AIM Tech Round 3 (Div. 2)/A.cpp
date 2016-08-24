// http://codeforces.com/contest/709/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, b, d, a;
  cin >> n >> b >> d;

  int ans = 0;
  long long tot = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    if (a > b) continue;
    tot += a;
    if (tot > d) {
      ans ++;
      tot = 0;
    }
  }

  cout << ans << endl;
  return 0;
}