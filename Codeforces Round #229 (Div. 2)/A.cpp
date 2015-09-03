// http://codeforces.com/contest/390/problem/A

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

const int MAXN = 101;
int mat[105][105];
int mat2[105][105];

int solve(){
  int v = 0, h = 0;
  for(int i=1; i<=MAXN; ++i){
    int tmp = 0;
    for(int j=1; j<=MAXN; ++j){
      tmp += mat[i][j];
      mat[i][j] = false;
    }

    if(tmp > 0)
      v++;
  }
  for(int i=1; i<=MAXN; ++i){
    int tmp = 0;
    for(int j=1; j<=MAXN; ++j){
      tmp += mat2[j][i];
      mat2[j][i] = false;
    }

    if(tmp > 0)
      h++;
  }

  return min(v,h);
}

int main(){__
  int n,x,y;
  cin >> n;

  memset(mat,0,sizeof mat);
  for(int i=0; i<n; ++i){
    cin >> x >> y;
    mat[x+1][y+1] = true;
    mat2[x+1][y+1] = true;
  }

  cout << solve();

  return 0;
}