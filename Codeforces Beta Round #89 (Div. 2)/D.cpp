// http://codeforces.com/contest/118/problem/D

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int n1,n2,k1,k2;
const int MOD = 100 * 1000 * 1000;
int dp[11][11][111][111];

int weed (int f, int h, int ff, int hh) {
  if (f > k1 || h > k2) return 0;
  if (ff + hh == n1 + n2) return 1;

  if (dp[f][h][ff][hh] != -1) return dp[f][h][ff][hh];

  int ans = 0;
  if ( ff + 1 <= n1 ) ans += weed (f + 1, 0, ff + 1, hh) % MOD;
  if ( hh + 1 <= n2 ) ans += weed (0, h + 1, ff, hh + 1) % MOD;

  return dp[f][h][ff][hh] = ans % MOD;
}

int main(){ __
  cin >> n1 >> n2 >> k1 >> k2;

  memset(dp, -1, sizeof dp);
  cout << weed (0,0,0,0);
  return 0;
}