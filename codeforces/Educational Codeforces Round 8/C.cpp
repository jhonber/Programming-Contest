// http://codeforces.com/contest/628/problem/C

#include <bits/stdc++.h>
using namespace std ;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() { IO
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  string abc = "abcdefghijklmnopqrstuvwxyz";
  string ans = s;

  for (int i = 0; i < n && k > 0; ++i) {
    int mx = 0;
    char c;
    for (int j = 25; j >= 0; --j) {
      int diff = abs(abc[j] - s[i]);
      if (diff <= k && diff > mx) {
        mx = diff;
        c = abc[j];
      }
    }

    k -= mx;
    ans[i] = c;
  }

  if (k > 0) cout << -1;
  else cout << ans;

  return 0;
}