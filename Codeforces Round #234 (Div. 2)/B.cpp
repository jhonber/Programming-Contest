// http://codeforces.com/contest/400/problem/B

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
  int n,m;
  cin >> n >> m;

  char mat[n][m];
  for(int i=0; i<n; ++i){
    for(int j=0; j<m; ++j){
      cin >> mat[i][j];
    }
  }

  set< int > ans;
  for(int i=0; i<n; ++i){
    int g,s;
    for(int j=0; j<m; ++j){
      if(mat[i][j] == 'G')
        g = j;
      if(mat[i][j] == 'S')
        s = j;
    }
    ans.insert( s-g );
    if(s<g){
      cout << -1;
      return 0;
    }
  }

  cout << ans.size();

  return 0;
}