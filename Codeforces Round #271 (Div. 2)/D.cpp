// http://codeforces.com/contest/474/problem/D

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

const int MOD = 1000000007;
vector<int> v(111111,0);
int dp [111111];
long long ans[100011];
int k;

int f (int t) {
  if (t < 0 ) return 0;

  if (dp[t] != -1) return dp[t];

  if (t == 0) return 1;

  int ans = 0;
  ans = ans + (f (t - 1) % MOD);
  ans = ans + (f (t - k) % MOD);

  return dp[t] = ans % MOD;
}

int main(){ __
  memset(dp, -1, sizeof dp);

  int t;
  cin >> t >> k;

  f (100010);


  ans[0] = 0LL;
  for (int i = 1; i < 100011; ++i)
    ans[i] = ans[i-1] + (dp[i] + 0LL);

  int a, b;
  for (int i = 0; i < t; ++i) {
    cin >> a >> b;
    cout << (ans[b] - ans[a-1]) % MOD << endl;
  }

  return 0;
}