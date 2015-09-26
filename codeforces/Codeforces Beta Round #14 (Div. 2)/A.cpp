// http://codeforces.com/contest/14/problem/A

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

int main () {
  int n, m;
  cin >> n >> m;

  char mat[n][m];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> mat[i][j];
    }
  }

  int fmin = INT_MAX;
  int fmax = -INT_MAX;
  int cmin = INT_MAX;
  int cmax = -INT_MAX;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == '*') {
        cmin = min(cmin, j);
        cmax = max(cmax, j);
      }
    }
  }

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (mat[j][i] == '*') {
        fmin = min(fmin, j);
        fmax = max(fmax, j);
      }
    }
  }

  for (int i = fmin; i <= fmax; ++i) {
    for (int j = cmin; j <= cmax; ++j) {
      cout << mat[i][j];
    }
    cout << endl;
  }

  return 0;
}