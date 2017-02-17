#include <bits/stdc++.h>
using namespace std;

vector<int> v;
long long dp[55][255];

long long go (int i, int n) {
  if (n == 0) return 1;
  if (i == v.size() || n < 0) return 0;
  if (dp[i][n] != -1) return dp[i][n];

  long long ans = 0;
  for (int j = i; j < v.size(); ++j) {
    long long a = 0;
    if (n - v[j] >= 0) {
      a = go(j, n - v[j]);
    }
    ans += a;
  }

  return dp[i][n] = ans;
}

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int c;
    cin >> c;
    v.push_back(c);
  }

  memset(dp, -1, sizeof dp);
  long long ans = go (0, n);
  cout << (n == 0 ? 0 : ans) << endl;

  return 0;
}

