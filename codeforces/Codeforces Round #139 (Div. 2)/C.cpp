// http://codeforces.com/contest/225/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int n, m, x, y;
long long pre[1111];
long long dp[1111][1111][3];

long long calc (int i, bool color) {
  if (!color) return n - pre[i];
  return pre[i];
}

long long go (int c, int size, bool color) {
  if (c == m) {
    if (size < x || size > y) return 1e6;
    return 0;
  }

  if (dp[c][size][color] != -1) return dp[c][size][color];

  long long best = LLONG_MAX;
  long long cost;

  if (size < x) {
    cost = calc(c, color);
    best = min(best, cost + go(c + 1, size + 1, color));
  }
  else {
    if (size + 1 <= y) {
      cost = calc(c, color);
      best = min(best, cost + go(c + 1, size + 1, color));
    }

    cost = calc(c, !color);
    best = min(best, cost + go(c + 1, 1, !color));
  }

  return dp[c][size][color] = best;
}

int main() {
  while (cin >> n >> m >> x >> y) {
    memset(pre, 0, sizeof pre);
    vector<string> mat(n);
    for (int i = 0; i < n; ++i) cin >> mat[i];

    for (int i = 0; i < m; ++i) {
      int cnt = 0;
      for (int j = 0; j < n; ++j) {
        if (mat[j][i] == '#') cnt ++;
      }

      pre[i] = n - cnt;
    }

    memset(dp, -1, sizeof dp);
    cout << min(go(0, 0, 0), go(0, 0, 1)) << endl;
  }

  return 0;
}