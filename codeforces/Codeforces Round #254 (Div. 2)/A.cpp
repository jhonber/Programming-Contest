// http://codeforces.com/contest/445/problem/A

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

int main(){ __
  int n,m;
  cin >> n >> m;

  char mat[n+2][m+2];
  memset (mat,'-',sizeof(mat));

  for (int i=1; i<=n; ++i){
    for (int j=1; j<=m; ++j){
      cin >> mat[i][j];
    }
  }

  for (int i=1; i<=n; i++){
    if(i%2 != 0){
      for (int j=1; j<=m; j+=2){
        if (mat[i][j] == '.')
          mat[i][j] = 'B';
      }
    }
    else {
      for (int j=2; j<=m; j+=2){
        if (mat[i][j] == '.')
          mat[i][j] = 'B';
      }
    }
  }

  for (int i=1; i<=n; i++){
    if(i%2 != 0){
      for (int j=2; j<=m; j+=2){
        if (mat[i][j] == '.')
          mat[i][j] = 'W';
      }
    }
    else {
      for (int j=1; j<=m; j+=2){
        if (mat[i][j] == '.')
          mat[i][j] = 'W';
      }
    }
  }

  for (int i=1; i<=n; ++i){
    for (int j=1; j<=m; ++j){
      cout << mat[i][j];
    }
    cout << endl;
  }


  return 0;
}
