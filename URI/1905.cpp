#include<bits/stdc++.h>
using namespace std;

int ans;
int n;
char mat[11][11];
int visited[11][11];

bool check(int x, int y) {
  return x < 0 || x >= n || y < 0 || y >= n;
}

void dfs(int x, int y) {
  if (!visited[x][y]) {
    visited[x][y] = true;

    if (x == n - 1 && y == n - 1) ans = true;

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0,  1, 0, -1};
    for (int i = 0; i < 4; ++i) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if (!check(xx, yy) && mat[xx][yy] == '0')
        dfs(xx, yy);
    }
  }
}

int main() {
  int t;
  cin >> t;

  n = 5;
  for (int i = 0; i < t; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        cin >> mat[j][k];
      }
    }

    memset(visited, 0, sizeof visited);
    ans = false;
    dfs(0, 0);
    if (ans) cout << "COPS" << endl;
    else cout << "ROBBERS" << endl;
  }

  return 0;
}
