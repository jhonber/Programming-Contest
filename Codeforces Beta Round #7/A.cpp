// http://codeforces.com/contest/7/problem/A

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

  char mat[8][8];
  for(int i=0; i<8; ++i){
    for(int j=0; j<8; ++j){
      cin >> mat[i][j];
    }
  }


  int hor = 0, ver = 0;

  for(int i=0; i<8; ++i){
    int f = true;
    for(int j=0; j<8; ++j){
      if(mat[i][j] != 'B'){
        f = false;
      }
    }
    if(f)
      hor ++;
  }

  for(int i=0; i<8; ++i){
    int f = true;
    for(int j=0; j<8; ++j){
      if(mat[j][i] != 'B'){
        f = false;
      }
    }
    if(f)
      hor ++;
  }

  if(hor + ver == 16) cout << 8;
  else cout << hor + ver;

  return 0;
}