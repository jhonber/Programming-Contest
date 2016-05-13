#include<bits/stdc++.h>
using namespace std;

int dp[55][55];

int solve (int i, int ant, int &n) {
  if (i == n) return 1;
  if (dp[i][ant] != -1) return dp[i][ant];

  int ans = 0;
  if (i + 1 <= n) ans += solve(i + 1, i, n);
  if (i + 2 <= n) ans += solve(i + 2, i, n);

  return dp[i][ant] = ans;
}

int main() {

  int n;
  while (cin >> n) {
    if (!n) break;

    vector<vector<int>> G(n + 1);

    for (int i = 0; i < 55; ++i) {
      for (int j = 0; j < 55; ++j) {
        dp[i][j] = -1;
      }
    }

    int ans = 0;
    ans += solve(1, 0, n);
    if (n > 1)
      ans += solve(2, 0, n);

    cout << ans << endl;
  }

  return 0;
}