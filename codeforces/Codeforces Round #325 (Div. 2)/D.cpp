// http://codeforces.com/contest/586/problem/D

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

int dfs (int x, int y, int &n, vector< vector<char> > &v, vector< vector<int> > &visited) {
  if (v[x][y] != '.' && v[x][y] != 's') return 0;
  if (v[x][y] == '.' && y == n - 1) return 1;

  int ans = 0;
  if (!visited[x][y]) {
    visited[x][y] = true;

    if (y + 3 < n && v[x][y + 1] == '.') {
      if (x - 1 >= 0 && v[x - 1][y + 1] == '.')
        ans += dfs (x - 1, y + 3, n, v, visited);

      if (x + 1 < 3 && v[x + 1][y + 1] == '.')
        ans += dfs (x + 1, y + 3, n, v, visited);

      ans += dfs (x, y + 3, n, v, visited);
    }
    if (y + 3 >= n) {
      int f = true;
      for (int i = y + 1; i < n; ++i) if (v[x][i] != '.')
        f = false;

      if (f) return 1;
    }
  }

  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t --> 0) {
    int n, c;
    cin >> n >> c;

    int x, y;
    vector< vector<char> > v(3, vector<char> (n));
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> v[i][j];
        if (v[i][j] == 's') {
          x = i; y = j;
        }
      }
    }

    vector< vector<int> > visited(3, vector<int> (n, 0));
    int ans = 0;
    ans += dfs(x, y, n, v, visited);

    cout << (ans ? "YES" : "NO") << endl;
  }
  return 0;
}