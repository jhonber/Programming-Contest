#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

bool check(int x, int y, int &n) {
  return x >= n || x < 0 || y >= n || y < 0;
}

int main() { IO
  int n;
  while (cin >> n) {
    if (!n) break;

    char mat[n][n];
    memset(mat, 'O', sizeof mat);

    bool visited[n][n];
    memset(visited, 0, sizeof visited);

    int x, y, midx, midy;
    x = y = n - 1;
    midx = midy = n / 2;

    int dx[] = { 0,-1, 0, 1};
    int dy[] = {-1, 0, 1, 0};

    int i = 0;
    vector<pair<int, int>> path;
    visited[x][y] = true;
    path.push_back({x, y});

    while (true) {
      if (x == midx && y == midy) break;
      while (true) {
        int x2 = x + dx[i % 4];
        int y2 = y + dy[i % 4];

        if (visited[x2][y2] || check(x2, y2, n)) break;

        visited[x2][y2] = true;
        path.push_back({x2, y2});
        x = x2;
        y = y2;
      }
      i ++;
    }

    reverse(path.begin(), path.end());
    int xlast = x;
    int ylast = y;
    for (int i = 0; i < path.size(); ++i) {
      int x = path[i].first;
      int y = path[i].second;

      mat[xlast][ylast] = 'O';
      mat[x][y] = 'X';

      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          cout << mat[i][j];
        }
        cout << endl;
      }
      cout << "@" << endl;
      xlast = x;
      ylast = y;
    }
  }

  return 0;
}