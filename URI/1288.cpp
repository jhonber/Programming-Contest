#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

int dp[55][333];

int go (int i, int k, int taken, vector< pair<int, int> > &v) {
  if (dp[i][k] != -1) return dp[i][k];
  if (i == v.size() || !k) return 0;
  int ans = 0;
  if (v[i].second <= k) {
    ans = max(ans, go (i + 1, k - v[i].second, true, v) + v[i].first);
  }

  ans = max(ans, go(i + 1, k, taken, v));

  return dp[i][k] = ans;
}

int main() { IO
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;

    vector< pair<int, int> > v(n);
    for (int j = 0; j < n; ++j) {
      int x, y;
      cin >> x >> y;
      v[j] = {x, y};
    }

    int k,r;
    cin >> k >> r;

    memset(dp, -1, sizeof dp);
    int ans = go (0, k, 0, v);
    if (ans >= r) cout << "Missao completada com sucesso" << endl;
    else cout << "Falha na missao" << endl;
  }
  return 0;
}
