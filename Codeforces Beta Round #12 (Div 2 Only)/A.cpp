// http://codeforces.com/contest/12/problem/A

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

  int mat[3][3];
  for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
    char c;
    cin >> c;
    if (c == 'X') mat[i][j] = true;
    else mat[i][j] = false;
  }

  int f = true;
  if (mat[0][0] && !mat[2][2] || !mat[0][0] && mat[2][2]) f = false;
  if (mat[0][1] && !mat[2][1] || !mat[0][1] && mat[2][1]) f = false;
  if (mat[1][0] && !mat[1][2] || !mat[1][0] && mat[1][2]) f = false;
  if (mat[2][0] && !mat[0][2] || !mat[2][0] && mat[0][2]) f = false;

  cout << (f ? "YES" : "NO");

  return 0;
}