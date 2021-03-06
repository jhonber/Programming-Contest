// http://codeforces.com/contest/577/problem/B

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

int n, m;
vector<int> v(1000011);
int dp[1111][1111][2];

int go (int i, int sum, bool taken) {
  if (dp[i][sum][taken] != -1) return dp[i][sum][taken];
  if (i > n) return 0;
  if (sum == 0 && taken) return 1;

  int ans = 0;
  ans += go (i + 1, (sum + v[i]) % m, true);
  ans += go (i + 1, sum, taken);

  return dp[i][sum][taken] = ans;
}

int main() {
  cin >> n >> m;

  int ans = false;
  if (n >= m) {
    cout << "YES";
    return 0;
  }

  for (int i = 0; i < n; ++i) cin >> v[i];

  memset(dp, -1, sizeof dp);
  ans = go (0, 0, 0);
  cout << (ans ? "YES" : "NO");
  return 0;
}