#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for (__typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int n;
int cost[22][5];
int dp[22][5];

int go (int i, int ant) {
  if (i >= n) return 0;
  if (dp[i][ant] != -1) return dp[i][ant];

  int ans = INT_MAX;
  for (int j = 0; j < 3; ++j) {
    if (j != ant) {
      int c = cost[i][j];
      ans = min(ans, go (i + 1, j) + c);
    }
  }

  return dp[i][ant] = ans;
}

int main() { __
  int T;
  cin >> T;

  int TC = 1;
  while (T --> 0) {
    cin >> n;

    for (int i = 0; i < n; ++i)
      cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

    memset(dp, -1, sizeof dp);
    int ans = INT_MAX;
    for (int j = 0; j < 3; ++j) {
      int c = cost[0][j];
      ans = min(ans, go (1, j) + c);
    }

    cout << "Case " << TC ++ << ": " << ans << endl;
  }

  return 0;
}
