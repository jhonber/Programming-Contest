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

int dp[111][111];

int go (int i, int j, string &s) {
  if (i == j) return 1;
  if (i > j) return 0;

  if (dp[i][j] != -1) return dp[i][j];

  int ans = 1;
  for (int k = i; k < j; ++k) {
    for (int l = k + 1; l < j; ++l) {
      if (s[k] == s[l]) {
        int d = 1;
        if (k + 1 == l) d = 2;
        ans = max(ans, go (k + d, l, s) + 2);
      }
    }
    ans = max(ans, go (k, k, s));
  }

  return dp[i][j] = ans;
}

int main() {
  string s;
  int T;
  cin >> T;

  int TC = 1;
  while (T --> 0) {
    cin >> s;
    int size = s.size();
    memset(dp, -1, sizeof dp);
    cout << "Case " << TC ++ << ": " << size - go(0, size, s) << endl;
  }

  return 0;
}
