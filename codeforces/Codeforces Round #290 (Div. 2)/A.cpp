// http://codeforces.com/contest/510/problem/A

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
  memset(mat,'#',sizeof mat);
  int f = 0;
  for (int i = 1; i < n; i += 2,++f) {
    int j = f % 2 != 0 ? 1 : 0;
    for (int k = 0; k < m-1; ++k) {
      mat[i][k+j] = '.';
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << mat[i][j];
    }
    cout << endl;
  }

  return 0;
}