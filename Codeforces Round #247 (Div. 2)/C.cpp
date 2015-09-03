// http://codeforces.com/contest/431/problem/C

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int n,k,d;
long long dp[200][200][5];
const long long M = 1000000007;

long long f(int i, int sum, int flag) {
  if (sum==n)
    return flag;

  if (dp[i][sum][flag] != -1)
    return dp[i][sum][flag];

  long long ans = 0;
  for (int j=1; j<=k; ++j) {
    if (sum + j > n) break;
    ans = ( f(i + 1, sum + j, flag or (j>=d)) + ans ) % M;
  }

  return dp[i][sum][flag] = ans;
}

int main() { __

  memset(dp,-1,sizeof dp);
  cin >> n >> k >> d;

  cout << f(0,0,0);
  return 0;
}