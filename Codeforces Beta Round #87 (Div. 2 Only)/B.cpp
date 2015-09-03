// http://codeforces.com/contest/116/problem/B

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

int n,m;
bool check(int i, int j) {
  if (i >=0 and i < n and j >= 0 and j < m) return true;
  return false;
}

int main() {
  cin >> n >> m;

  int ant = 0;
  char mat[n][m];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> mat[i][j];
      if (mat[i][j] == 'P') ant ++;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == 'W') {
        for (int k = 7, cnt = 0; cnt < 4; k += 2, ++ cnt) {
          int a = i + dx[k % 8];
          int b = j + dy[k % 8];
          if (check(a, b) and mat[a][b] == 'P') {
            mat[a][b] = mat[i][j] = '.';
            break;
          }
        }
      }
    }
  }

  int bef = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == 'P') bef ++;
    }
  }

  cout << ant - bef;

  return 0;
}