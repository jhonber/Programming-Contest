// http://codeforces.com/contest/616/problem/C

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int n, m;
char mat[1010][1010];
int visited[1010][1010];
map<int, int> size;

bool check(int x, int y) {
  return x >= n || x < 0 || y >= m || y < 0;
}

void dfs(int x, int y, int n) {
  if (!visited[x][y]) {
    visited[x][y] = n;
    size[n] ++;
    int dx[] = { 0,1,0,-1};
    int dy[] = {-1,0,1, 0};

    for (int k = 0; k < 4; ++k) {
      int xx = dx[k] + x;
      int yy = dy[k] + y;
      if (!check(xx, yy) && mat[xx][yy] != '*') {
        dfs(xx, yy, n);
      }
    }
  }
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) {
      mat[i][j] = s[j];
    }
  }


  memset(visited, 0, sizeof visited);

  int cnt = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] != '*') {
        dfs(i, j, cnt);
        cnt ++;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == '*') {
        int dx[] = { 0,1,0,-1};
        int dy[] = {-1,0,1, 0};

        set<int> ready;
        int tot = 1;
        for (int k = 0; k < 4; ++k) {
          int xx = dx[k] + i;
          int yy = dy[k] + j;
          if (!check(xx, yy) && mat[xx][yy] != '*' && ready.count(visited[xx][yy]) == 0) {
            tot += size[visited[xx][yy]];
            ready.insert(visited[xx][yy]);
          }
        }
       cout << tot % 10;
      }
      else cout << ".";
    }
    cout << endl;
  }

  return 0;
}
