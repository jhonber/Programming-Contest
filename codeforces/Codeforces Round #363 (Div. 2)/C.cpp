// http://codeforces.com/contest/699/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int n;
vector<int> v(111);
int dp[111][111];

int go (int i, int ant) {
  if (i == n) return 0;

  if (dp[i][ant] != -1) return dp[i][ant];

  int ans = INT_MAX;
  if (v[i] == 0) {
    ans = min(go(i + 1, 3) + 1, ans);
  }
  else if (v[i] == 3) {
    int a = (ant != 0 ? go(i + 1, 0) : INT_MAX);
    int b = (ant != 1 ? go(i + 1, 1) : INT_MAX);

    ans = min(min(a, b), ans);
  }
  else if (v[i] == 1) {
    if (ant != 0) {
      int a = go(i + 1, 0);
      ans = min(a, ans);
    }
    else ans = min(go(i + 1, 3) + 1, ans);
  }
  else if (v[i] == 2) {
    if (ant != 1) {
      int a = go(i + 1, 1);
      ans = min(a, ans);
    }
    else ans = min(go(i + 1, 3) + 1, ans);
  }

  return dp[i][ant] = ans;
}

int main() {
  cin >> n;

  for (int i = 0; i < n; ++i) cin >> v[i];

  for (int i = 0; i < 111; ++i)
    for (int j = 0; j < 111; ++j)
      dp[i][j] = -1;

  cout << go(0, 3) << endl;
  return 0;
}