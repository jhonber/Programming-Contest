// http://codeforces.com/contest/580/problem/D

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

long long G[22][22];
long long dp[22][1 << 20];
vector<int> v(22);
int n, m, k;

long long go (int last, int mask) {
  if (__builtin_popcount(mask) == m) return 0LL;
  if (dp[last][mask] != -1) return dp[last][mask];

  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (!(mask & (1 << i))) {
      long long tmp = 0;
      if (last > 0) tmp = G[last][i];
      ans = max(ans, go (i, mask | (1 << i)) + v[i] + tmp);
    }
  }

  return dp[last][mask] = ans;
}

int main() {
  cin >> n >> m >> k;

  for (int i = 1; i <= n; ++i) cin >> v[i];

  int a, b, c;
  for (int i = 0; i < k; ++i) {
    cin >> a >> b >> c;
    G[a][b] = c;
  }

  memset(dp, -1, sizeof dp);
  cout << go (0, 0);
  return 0;
}