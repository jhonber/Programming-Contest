// http://codeforces.com/contest/8/problem/B

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

const int MAXNODES = 111;

unsigned long long G[MAXNODES][MAXNODES];
void floyd(int n){
  //Llenar g antes
  for (int k=0; k<n; ++k){
    for (int i=0; i<n; ++i){
      for (int j=0; j<n; ++j){
        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
      }
    }
  }
}

int main() {
  string path;
  cin >> path;

  int end;
  int cost = path.size();
  int mat[222][222];
  memset(mat, 0, sizeof mat);

  int curx = 111;
  int cury = 111;
  mat[curx][cury] = true;

  memset(G,INT_MAX,sizeof G);
  map< pair<int,int>, int > mapa;
  mapa[ make_pair(curx, cury) ] = 1;
  end = 1;
  int c = 2;

  for (int i = 0; i < cost; ++i) {
    if (path[i] == 'U') {
      curx --;
      mat[curx][cury] = true;
    }
    else if (path[i] == 'R') {
      cury ++;
      mat[curx][cury] = true;
    }
    else if (path[i] == 'D') {
      curx ++;
      mat[curx][cury] = true;
    }
    else if (path[i] == 'L') {
      cury --;
      mat[curx][cury] = true;
    }

    if ( mapa.find( make_pair(curx,cury) ) == mapa.end() )
      mapa[ make_pair(curx,cury) ] = c++;
    end = mapa[ make_pair(curx,cury) ];
  }

  foreach (x, mapa) {
    int i = x -> first.first;
    int j = x -> first.second;
    int a = x -> second;

    for (int k = 1; k < 8; k += 2) {
      if ( mat[i + dx[k]][j + dy[k]] ) {
        int b = mapa[make_pair(i + dx[k], j + dy[k])];
        G[ a ][ b ] = true;
        G[ b ][ a ] = true;
      }
    }
  }

  floyd(111);

  if ( cost == G[1][end] ) cout << "OK";
  else cout << "BUG";

  return 0;
}