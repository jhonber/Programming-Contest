// http://codeforces.com/contest/486/problem/B


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

int main(){ //__
  int m,n;
  cin >> m >> n;

  int mat[m][n];
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> mat[i][j];
    }
  }

  int ans[m][n];
  memset(ans, -1, sizeof ans);

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (mat[i][j]) continue;
      for (int k = 0; k < m; ++k)
        ans[k][j] = 0;

      for (int k = 0; k < n; ++k)
        ans[i][k] = 0;
    }
  }

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (ans[i][j] < 0)
        ans[i][j] = 1;
    }
  }

  int mat2[m][n];
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      int row = 0;
      int col = 0;
      for (int k = 0; k < m; ++k)
        col = col or ans[k][j];

      for (int k = 0; k < n; ++k)
        row = row or ans[i][k];

      mat2[i][j] = row or col;
    }
  }

  int f = true;
  for (int i = 0; i < m; ++i){
    for (int j = 0; j < n; ++j) {
      if (mat2[i][j] != mat[i][j]) {
        f = false;
      }
    }
  }

  if (f) {
    cout << "YES" << endl;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << ans[i][j] << " ";
      }
      cout << endl;
    }
  }
  else cout << "NO";

  return 0;
}