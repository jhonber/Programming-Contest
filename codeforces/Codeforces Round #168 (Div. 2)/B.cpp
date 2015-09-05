// http://codeforces.com/contest/275/problem/B

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
  int n,m;
  cin >> n >> m;

  char board[55][55];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> board[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (board[i][j] == 'B') {
        for (int k = 0; k < n; ++k) {
          for (int l = 0; l < m; ++l) {
            if (i != k and j != l and board[k][l] == 'B') {
              if (board[k][j] != 'B' and board[i][l] != 'B') {
                cout << "NO";
                return 0;
              }
            }
          }
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    int f1 = 0, f2 = 0, j = 0;
    for ( ; j < m; ++j) {
      if (board[i][j] == 'B' and j + 1 < m and board[i][j + 1] == 'W') { f1 ++; break; }
    }
    j ++;
    for (; j < m; ++j) {
      if (board[i][j] == 'W' and j + 1 < m and board[i][j + 1] == 'B') { f2 ++; break; }
    }

    if (f1 and f2) {
      cout << "NO";
      return 0;
    }
  }



  for (int i = 0; i < m; ++i) {
    int f1 = 0, f2 = 0, j = 0;
    for ( ; j < n; ++j) {
      if (board[j][i] == 'B' and j + 1 < n and board[j + 1][i] == 'W') { f1 ++; break; }
    }
    j ++;
    for ( ; j < n; ++j) {
      if (board[j][i] == 'W' and j + 1 < n and board[j + 1][i] == 'B') { f2 ++; break; }
    }

    if (f1 and f2) {
      cout << "NO";
      return 0;
    }
  }


  cout << "YES";
  return 0;
}