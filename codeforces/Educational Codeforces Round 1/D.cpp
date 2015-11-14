// http://codeforces.com/contest/598/problem/D

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);

int dx[] = {-1, 0, 1, 0};
int dy[] = { 0, 1, 0, -1};
char mat[1100][1100];
int  mark[1100][1100];
int  ans[1000100];


void dfs (int x, int y, int &ans, int ind) {
  if (!mark[x][y]) {
    mark[x][y] = ind;

    for (int i = 0; i < 4; ++i) {
      int x2 = x + dx[i];
      int y2 = y + dy[i];
      if (mat[x2][y2] == '*') ans ++;
      else dfs(x2, y2, ans, ind);
    }
  }
}

int main() { IO
  int n,m,k;
  cin >> n >> m >> k;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> mat[i][j];
    }
  }

  memset(mark, 0, sizeof mark);
  memset(ans, 0, sizeof ans);

  int ind = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == '.') {
        int tot = 0;
        dfs(i, j, tot, ind);
        ans[ind] = tot;
        ind ++;
      }
    }
  }

  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y; x--; y--;
    cout << ans[mark[x][y]] << endl;
  }

  return 0;
}