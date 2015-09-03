// http://codeforces.com/contest/131/problem/C

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

long long mat[35][35];

void PascalTriangle(int n){
  for (int i=0; i<n; ++i){
    mat[i][0] = 1;
    mat[i][i] = 1;
  }

  for (int i=1; i<n; ++i){
    for (int j=1; j<=i; ++j){
      mat[i+1][j] = mat[i][j] + mat[i][j-1];
    }
  }
}

int main(){ __

  PascalTriangle(32);
  int n,m,t;
  cin >> n >> m >> t;

  long long ans = 0;
  for (int i=4; i<=n; ++i){
    for (int j=1; j<=m; ++j){
      if (i+j == t)
        ans += mat[n][i] * mat[m][j];
    }
  }

  cout << ans;

  return 0;
}