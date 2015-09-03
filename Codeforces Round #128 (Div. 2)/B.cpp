// http://codeforces.com/contest/203/problem/B

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

int mat[1010][1010];

bool check(int x, int y) {
  if (x < 0 || y < 0)
    return false;

  for (int i=0; i<3; ++i) {
    for (int j=0; j<3; ++j) {
      if (!mat[x+i][y+j])
        return false;
    }
  }

  return true;
}

int main(){ __
  int n,m;
  cin >> n >> m;

  memset (mat,0, sizeof mat);
  int x,y;

  for (int i=0; i<m; ++i) {
    cin >> x >> y; x--; y--;
    mat[x][y] = true;

    if (check(x,y) || check(x,y-1) || check(x,y-2) || check(x-1,y) || check(x-1,y-1) || check(x-1,y-2) || check(x-2,y) || check(x-2,y-1) || check(x-2,y-2)) {
      cout << i+1;
      return 0;
    }
  }

  cout << -1;

  return 0;
}