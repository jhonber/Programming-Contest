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

int n, x;
long long dp[33][222];
long long go (int i, int sum) {
  if (i > n) {
    if (sum >= x) return 1;
    return 0;
  }

  if (dp[i][sum] != -1) return dp[i][sum];

  long long ans = 0;
  for (int k = 1; k < 7; ++k)
    ans += go (i + 1, sum + k);

  return dp[i][sum] = ans;
}

int main() { __
  int T;
  cin >> T;

  int TC = 1;
  while (T --> 0) {
    cin >> n >> x;

    memset(dp, -1, sizeof dp);
    long long good = go (1, 0);
    long long tot = pow(6, n);
    long long k = __gcd(good, tot);

    good /= k;
    tot  /= k;

    if (tot == 1 || !good)
      cout << "Case " << TC << ": " << good << endl;
    else
      cout << "Case " << TC << ": " << good << "/" << tot << endl;
    TC ++;
  }

  return 0;
}
