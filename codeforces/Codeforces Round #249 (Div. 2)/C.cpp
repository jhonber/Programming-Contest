// http://codeforces.com/contest/435/problem/C

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

int main(){ __
  int n;
  cin >> n;

  char mat[2222][2222];
  memset(mat,' ',sizeof mat);

  int x = 2222/2;
  int y = 0;

  int a,maxx = 0,maxy = 0,minx = 55555,miny = 0;
  for (int i=0; i<n; ++i) {
    cin >> a;
    if (i%2 == 0) {
      for (int j=0; j<a; ++j, --x, ++y) {
        mat[x][y] = '.';
        maxx = max(x,maxx);
        minx = min(x,minx);
        maxy = max(y,maxy);
      }
    }
    else {
      ++x;
      for (int j=0; j<a; ++j, ++x, ++y) {
        mat[x][y] = '*';
        maxx = max(x,maxx);
        minx = min(x,minx);
        maxy = max(y,maxy);
      }
      --x;
    }
  }

  for (int i=minx; i<=maxx; ++i) {
    for (int j=miny; j<=maxy; ++j) {
      if (mat[i][j] == ' ') cout << " ";
      else cout << (mat[i][j] == '.' ? "/" : "\\");
    }
    cout << endl;
  }


  return 0;
}