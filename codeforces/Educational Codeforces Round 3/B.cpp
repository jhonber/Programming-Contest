// http://codeforces.com/contest/609/problem/B

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

  int pre[11][200010];
  memset(pre, 0, sizeof pre);

  for (int i = 1; i <= 10; ++i) {
    for (int j = n; j > 0; --j) {
      if (v[j] == i) {
        pre[i][j] = pre[i][j + 1] + 1;
      }
      else {
        pre[i][j] = pre[i][j + 1];
      }
    }
  }

  int ans = 0;
  int cnt = n - 1;
  for (int i = 1; i <= n; ++i) {
    ans += cnt - pre[v[i -1]][i];
    cnt --;
  }

  cout << ans;

  return 0;
}