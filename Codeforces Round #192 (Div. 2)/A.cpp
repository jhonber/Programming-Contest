// http://codeforces.com/contest/330/problem/A

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

int main() {
  int n,m;
  cin >> n >> m;

  char mat[n][m];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> mat[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    int f = true;
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == 'S') f = false;
    }
    if (!f) continue;
    for (int j = 0; j < m; ++j) {
      mat[i][j] = 'x';
    }
  }

  for (int i = 0; i < m; ++i) {
    int f = true;
    for (int j = 0; j < n; ++j) {
      if (mat[j][i] == 'S') f = false;
    }
    if (!f) continue;
    for (int j = 0; j < n; ++j) {
      mat[j][i] = 'x';
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == 'x') ans ++;
    }
  }

  cout << ans;

  return 0;
}