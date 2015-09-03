// http://codeforces.com/contest/371/problem/A

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
  int n,k;
  cin >> n >> k;

  int mat[n/k][k];
  for(int i=0; i<n/k; ++i){
    for(int j=0; j<k; ++j){
      cin >> mat[i][j];
    }
  }

  int ans = 0;
  for(int i=0; i<k; ++i){
    int ones = 0, twos = 0;
    for(int j=0; j<n/k; ++j){
      if(mat[j][i] == 1)
        ones ++;
      else
        twos ++;
    }
    ans += min(ones,twos);
  }

  cout << ans;

  return 0;
}
