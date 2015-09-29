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
int mat[22][22];
int dp[18][1 << 18];


int go (int row, int mask) {
  if (row >= n) return 0;
  if (dp[row][mask] != -1) return dp[row][mask];

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if ( !(mask & (1 << i)) ) {
      int ind = n - i - 1;
      ans = max(ans, go (row + 1, mask | (1 << i)) + mat[row][ind]);
    }
  }

  return dp[row][mask] = ans;
}

int main() { __
  int T;
  cin >> T;

  int TC = 1;
  while (T --> 0) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> mat[i][j];
      }
    }

    memset(dp, -1, sizeof dp);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int ind = n - i - 1;
      ans = max(ans, go (1, (1 << i)) + mat[0][ind]);
    }

    cout << "Case " << TC++ << ": " << ans << endl;
  }
}
