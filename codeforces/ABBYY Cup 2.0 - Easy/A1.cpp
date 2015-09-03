// http://codeforces.com/contest/177/problem/A1

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

  int mat[n][n];
  int tot = 0;
  for(int i=0; i<n; ++i){
    for(int j=0; j<n; ++j){
      cin >> mat[i][j];
      tot += mat[i][j];
    }
  }

  if(n<=3) cout << tot;
  else {
    if(n==4){
      cout << tot - (mat[0][1] + mat[0][2] + mat[1][0] + mat[2][0] + mat[1][n-1] + mat[2][n-1] + mat[n-1][1] + mat[n-1][2]);
    }
    else {
      cout << tot - ( mat[0][1] + mat[0][3] + mat[1][0] + mat[3][0] + mat[1][n-1] + mat[3][n-1] + mat[n-1][1] + mat[n-1][3] );
    }
  }
  return 0;
}