// http://codeforces.com/contest/431/problem/B

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

int main(){__
  int v[5]={1,2,3,4,5};
  int mat[6][6];

  for(int i=1; i<=5; ++i){
    for(int j=1; j<=5; ++j){
      cin >> mat[i][j];
    }
  }

  int ans = 0;

  do {
    int tmp[6] = {0,0,0,0,0,0};
    tmp[v[0]] += mat[v[0]][v[1]];
    tmp[v[1]] += mat[v[1]][v[0]];
    tmp[v[2]] += mat[v[2]][v[3]];
    tmp[v[3]] += mat[v[3]][v[2]];

    tmp[v[1]] += mat[v[1]][v[2]];
    tmp[v[2]] += mat[v[2]][v[1]];
    tmp[v[3]] += mat[v[3]][v[4]];
    tmp[v[4]] += mat[v[4]][v[3]];

    tmp[v[2]] += mat[v[2]][v[3]];
    tmp[v[3]] += mat[v[3]][v[2]];

    tmp[v[3]] += mat[v[3]][v[4]];
    tmp[v[4]] += mat[v[4]][v[3]];

    int t = 0;
    for(int i=1; i<=5; ++i)
      t += tmp[i];

    ans = max(ans,t);
  }
  while(next_permutation(v,v+5));


  cout << ans;

  return 0;
}