// http://codeforces.com/contest/711/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

const long long inf = 1e12;

int n, m, k;
vector<int> v(111);
vector<int> p[111];
long long dp[111][111][111];

long long go (int i, int ant, int cnt) {
  if (i == n) {
    if (cnt == k) return 0;
    else return inf;
  }

  if (dp[i][ant][cnt] != -1) return dp[i][ant][cnt];

  long long ans = inf;
  if (!v[i]) {
    for (int j = 0; j < m; ++j) {
      int t = 0;
      if (ant != j + 1) t ++;
      if (cnt + t <= k) {
        ans = min(ans, go (i + 1, j + 1, cnt + t) + p[i][j]);
      }
    }
  }
  else {
    int t = 0;
    if (ant != v[i]) t ++;
    if (cnt + t <= k)
      ans = min(ans, go (i + 1, v[i], cnt + t));
  }

  return dp[i][ant][cnt] = ans;
}

int main() { IO
  cin >> n >> m >> k;

  for (int i = 0; i < n; ++i) cin >> v[i];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int a;
      cin >> a;
      p[i].push_back(a);
    }
  }

  for (int i = 0; i < 111; ++i)
    for (int j = 0; j < 111; ++j)
      for (int l = 0; l < 111; ++l)
        dp[i][j][l] = -1;

  long long ans = inf;
  if (!v[0]) {
    for (int i = 0; i < m; ++i) {
      ans = min(ans, p[0][i] + go(1, i + 1, 1));
    }
  }
  else {
    ans = min(ans, go(1, v[0], 1));
  }

  cout << (ans == inf ? -1 : ans) << endl;

  return 0;
}