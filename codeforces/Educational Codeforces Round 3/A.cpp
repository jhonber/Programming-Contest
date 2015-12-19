// http://codeforces.com/contest/609/problem/A

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(NULL); cie.tie(false);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());

  int ans = 0;
  int tot = 0;
  for (int i = 0; i < n && tot < m; ++i) {
    tot += v[i];
    ans ++;
  }

  cout << ans;
  return 0;
}