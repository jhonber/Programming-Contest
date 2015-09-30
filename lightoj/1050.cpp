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

double dp[505][505];

double go (int r, int b) {
  if (r + b == 1) {
    if (!b) return 0;
    return 1;
  }

  if (dp[r][b] != -1) return dp[r][b];

  double ans = 0;
  if ((r + b) % 2 != 0) {
    if (r > 0) {
      double p = (1. / (r + b)) * r;
      ans += go (r - 1, b) * p;
    }

    if (b > 0) {
      double p = (1. / (r + b)) * b;
      ans += go (r, b - 1) * p;
    }
  }
  else
    if (b > 0) ans += go (r, b - 1);

  return dp[r][b] = ans;
}

int main() { __
  int T;
  cin >> T;

  for (int i = 0; i < 505; ++i)
    for (int j = 0; j < 505; ++j)
      dp[i][j] = -1;

  int TC = 1;
  while (T --> 0) {
    int r, b;
    cin >> r >> b;
    double ans = go(r, b);
    printf("Case %d: %.10lf\n", TC ++, ans);
  }

  return 0;
}
