// http://codeforces.com/contest/462/problem/A

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

  char mat[n+2][n+2];
  memset(mat,' ',sizeof mat);

  for (int i=0; i<n; ++i) {
    for (int j=0; j<n; ++j) {
      cin >> mat[i][j];
    }
  }

  for (int i=0; i<n; ++i) {
    for (int j=0; j<n; ++j) {
      int c = 0;
      for (int x=1; x<8; x+=2 ) {
        if (mat[i+dx[x]][j+dy[x]] == 'o') {
          c++;
        }
      }
      if (c%2 != 0) {
        cout << "NO";
        return 0;
      }
    }
  }

  cout << "YES";

  return 0;
}