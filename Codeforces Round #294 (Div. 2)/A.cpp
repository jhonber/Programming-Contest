// http://codeforces.com/contest/519/problem/A

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for (__typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main() {
  map<char,int> mapa;
  mapa['q'] = 9;
  mapa['r']= 5;
  mapa['b']= 3;
  mapa['n']= 3;
  mapa['p'] = 1;
  mapa['k'] = 0;

  char mat[8][8];
  for (int i = 0; i < 8; ++i ) {
    for (int j = 0; j < 8; j++) {
      cin >> mat[i][j];
    }
  }

  int a = 0, b = 0;
  for (int i = 0; i < 8; ++i ) {
    for (int j = 0; j < 8; j++) {
      if (mat[i][j] != '.') {
        if(islower(mat[i][j])){
          a += mapa[mat[i][j]];
        }
        else{
          b += mapa[tolower(mat[i][j])];
        }
      }
    }
  }

  if (a == b) cout << "Draw";
  else if (a < b) cout << "White";
  else cout << "Black";
  return 0;
}