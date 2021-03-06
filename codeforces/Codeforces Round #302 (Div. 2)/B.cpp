// http://codeforces.com/contest/544/problem/B

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

int n;
char mat[111][111];
int visited[111][111];

bool check(int x, int y) {
  if (x >= 0 && x < n && y >= 0 && y < n) {
    int f = true;
    for (int i = 1; i < 8; i += 2) {
      if (mat[x + dx[i]][y + dy[i]] == 'L')
        f = false;
    }
    return f;
  }
  return false;
}

void fill (int x, int y) {
  if (!visited[x][y]) {
    visited[x][y] = true;
    for (int i = 1; i < 8; i += 2) {
      int a = x + dx[i];
      int b = y + dy[i];
      if (check(a,b)) {
        mat[a][b] = '*';
        fill(a,b);
      }
    }
  }
}

int main() {
  int k;
  cin >> n >> k;

  memset(mat, 'S', sizeof mat);
  memset(visited, 0, sizeof visited);

  int tot = 0;
  int f = true;
  int x,y;
  for (int i = 0; i < n; ++i) {
    for (int j = i % 2; j < n && f && k; j += 2) {
      mat[i][j] = 'L';
      x = i; y = j;
      tot ++;
      if (tot == k) f = false;
    }
  }

  if (k) mat[x][y] = '*';
  if (tot < k) {
    cout << "NO";
  }
  else {
    if (k) fill(x,y);
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == '*') cout << "L";
        else cout << mat[i][j];
      }
      cout << endl;
    }
  }

  return 0;
}