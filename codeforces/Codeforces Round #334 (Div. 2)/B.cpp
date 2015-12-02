// http://codeforces.com/contest/604/problem/B

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(NULL); cie.tie(false);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  reverse(v.begin(), v.end());

  int ans = *max_element(v.begin(), v.end());
  for (int i = k - 1, ind = k; i >= 0 && ind < n; --i, ind ++) {
    ans = max(ans, v[i] + v[ind]);
  }

  cout << ans;
  return 0;
}