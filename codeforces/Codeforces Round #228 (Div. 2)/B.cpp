// http://codeforces.com/contest/389/problem/B

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main(){__
  int n;
  cin >> n;

  char mat[n+2][n+2];
  for(int i=0; i<n+2; ++i){
    for(int j=0; j<n+2; ++j){
      mat[i][j] = '.';
    }
  }

  for(int i=1; i<n+1; ++i){
    for(int j=1; j<n+1; ++j){
      cin >> mat[i][j];
    }
  }

  for(int i=1; i<n+1; ++i){
    for(int j=1; j<n+1; ++j){
      if(mat[i][j] == '#' && mat[i+dx[1]][j+dy[1]]=='#' && mat[i+dx[3]][j+dy[3]]=='#' && mat[i+dx[5]][j+dy[5]]=='#' && mat[i+dx[7]][j+dy[7]]=='#' ){
        mat[i][j] = '.';
        mat[i+dx[1]][j+dy[1]] = '.';
        mat[i+dx[3]][j+dy[3]] = '.';
        mat[i+dx[5]][j+dy[5]] = '.';
        mat[i+dx[7]][j+dy[7]] = '.';
      }
    }
  }

  int ans = true;
  for(int i=1; i<n+1; ++i){
    for(int j=1; j<n+1; ++j){
      if(mat[i][j] == '#'){
        cout << "NO";
        return 0;
      }
    }
  }

  cout << "YES";

  return 0;
}