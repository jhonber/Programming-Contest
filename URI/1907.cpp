#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int n, m;
char mat[1033][1033];
int dx[] = {-1, 0, 1, 0};
int dy[] = { 0, 1, 0,-1};

bool check(int x, int y) {
  return x >= n || y >= m || x < 0 || y < 0;
}

void dfs(int x, int y) {
  mat[x][y] = 'x';

  for (int i = 0; i < 4; ++i) {
    int x2 = x + dx[i];
    int y2 = y + dy[i];

    if (!check(x2, y2) && mat[x2][y2] == '.') {
      dfs(x2, y2);
    }
  }
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> mat[i][j];
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == '.') {
        dfs(i, j);
        ans ++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}