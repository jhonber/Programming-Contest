// http://codeforces.com/contest/157/problem/A

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;
#define MN 4004

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int n;
int mat[40][40];

int f(int a, int b){
  int f = 0;
  int c = 0;

  for(int i=0; i<n; ++i)
    f += mat[a][i];

  for(int i=0; i<n; ++i)
    c += mat[i][b];

  if( c>f ) return 1;

  return 0;
}

int main(){

  cin  >> n;

  for(int i=0; i<n; ++i){
    for(int j=0; j<n; ++j){
      cin >> mat[i][j];
    }
  }

  int ans = 0;
  for(int i=0; i<n; ++i){
    for(int j=0; j<n; ++j){
      ans += f(i,j);
    }
  }

  cout << ans;
  return 0;
}