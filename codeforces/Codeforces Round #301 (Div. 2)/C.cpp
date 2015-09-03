// http://codeforces.com/contest/540/problem/C

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

int n,m,x2,y2;
char mat[555][555];
int visited[555][555];

bool check(int x, int y) {
  if (x >= 0 && x < n && y >= 0 && y < m) return true;
  return false;
}

bool dfs(int x, int y) {
  if (x == x2 && y == y2) {
    if (mat[x][y] == 'X') return true;
    int cnt = 0;
    for (int i = 1; i < 8; i += 2) {
      int a = x + dx[i];
      int b = y + dy[i];
      if (check(a,b) && mat[a][b] == '.') cnt ++;
    }
    if (cnt >= 2) return true;
    return false;
  }

  int ans = 0;
  if (!visited[x][y]) {
    visited[x][y] = true;
    if (mat[x][y] != 'X') {
      for (int i = 1; i < 8; i += 2) {
        int a = x + dx[i];
        int b = y + dy[i];
        if (check(a,b)) ans += dfs(a,b);
      }
    }
  }

  return ans;
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> mat[i][j];
    }
  }

  int x,y;
  cin >> x >> y >> x2 >> y2;
  x --; y --; x2 --; y2 --;

  memset(visited, 0, sizeof visited);
  int op = 0;
  if (x == x2 && y == y2) op = 1;
  else {
    for (int i = 1; i < 8; i += 2) {
      int a = x + dx[i];
      int b = y + dy[i];
      if (check(a,b) && a == x2 && b == y2) op = 2;
    }
  }

  int ans = 0;
  if (!op) {
    for (int i = 1; i < 8; i += 2) {
      int a = x + dx[i];
      int b = y + dy[i];
      if (check(a,b)) ans += dfs(a,b);
    }
  }
  else {
    int cnt = 0;
    for (int i = 1; i < 8; i += 2) {
      int a = x2 + dx[i];
      int b = y2 + dy[i];
      if (check(a,b) && mat[a][b] == '.') cnt ++;
    }
    if ((mat[x2][y2] == 'X' && op == 2) || cnt > 0) ans = true;
    else ans = false;
  }

  cout << (ans ? "YES" : "NO");
  return 0;
}