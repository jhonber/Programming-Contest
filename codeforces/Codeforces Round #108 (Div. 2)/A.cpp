// http://codeforces.com/contest/152/problem/A

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

int main() {__
  int n,m;
  cin >> n >> m;
  int mat[n][m];
  string s;

  for (int i = 0; i < n; ++i) {
    cin >> s;
    for (int j = 0; j < m; ++j)
      mat[i][j] = (int)s[j] - '0';
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int f = true;
      for (int k = 0; k < n; ++k) {
        if (mat[i][j] < mat[k][j]) {
          f = false;
          break;
        }
      }
      if (f) {
        ans ++;
        break;
      }
    }
  }

  cout << ans;
  return 0;
}