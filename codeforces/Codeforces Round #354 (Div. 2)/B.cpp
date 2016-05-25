// http://codeforces.com/contest/676/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, t;
  cin >> n >> t;

  vector<double> dp[n];

  int cnt = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < cnt; ++j) {
      dp[i].push_back(0);
    }
    cnt ++;
  }

  dp[0][0] = t;
  for (int i = 0; i + 1 < n; ++i) {
    for (int j = 0; j < dp[i].size(); ++j) {
      double exc = dp[i][j] - 1;
      if (exc > 0) {
        dp[i][j] = 1;
        dp[i + 1][j] += exc * 0.5;
        dp[i + 1][j + 1] += exc * 0.5;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < dp[i].size(); ++j) if (dp[i][j] >= 1) ans ++;
  }

  cout << ans << endl;
  return 0;
}