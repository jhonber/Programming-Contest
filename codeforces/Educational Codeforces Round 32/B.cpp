// http://codeforces.com/contest/888/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int n;
string s;

int dp[111][233][233];
map<char, int> dx, dy;

int go (int i, int x, int y) {
  if (dp[i][x][y] != -1) return dp[i][x][y];
  if (i >= n) {
    if (x == 111 && y == 111) return 0;
    return -1e9;
  }

  int a = go(i + 1, x, y);
  int b = 1 + go(i + 1, x + dx[s[i]], y + dy[s[i]]);

  return dp[i][x][y] = max(a, b);
}

int main() {
  dx['L'] = dy['D'] = -1;
  dx['R'] = dy['U'] = 1;

  while (cin >> n) {

    int tot = 0;
    cin >> s;

    memset(dp, -1, sizeof dp);
    int ans = go(0, 111, 111);
    cout << ans << endl;
  }

  return 0;
}