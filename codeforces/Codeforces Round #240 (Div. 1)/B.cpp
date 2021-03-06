// http://codeforces.com/contest/414/problem/B

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

const long long mod = 1000000007;
long long n,k;

long long dp[2002][2002];

long long f (long long i, long long t) {
  if (dp[i][t] != -1) return dp[i][t];
  if (t == k) return 1;

  long long ans = 0;
  for (long long j = 1; j * i <= n; ++j) {
    if ((j * i) % i != 0) continue;
    ans += f (j * i, t + 1) % mod ;
  }

  return dp[i][t] = ans % mod;

}

int main() { __
  cin >> n >> k;

  memset(dp, -1, sizeof dp);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    long long t = f (i,1);
    ans += t % mod;
  }

  cout << ans % mod;

  return 0;
}