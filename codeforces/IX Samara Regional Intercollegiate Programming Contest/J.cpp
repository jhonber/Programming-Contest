// http://codeforces.com/problemset/gymProblem/100971/J

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

bool ok = 0;
bool good = 0;
int n, m;
map<pair<int, int>, char> mat;
map<pair<int, int>, bool> visited;
int dx[] = {-1, 0, 1, 0};
int dy[] = { 0, 1, 0,-1};

bool check(int x, int y) {
  return x < 0 || x >= n || y < 0 || y >= m || mat[{x, y}] == '#';
}

void dfs (int x, int y) {
  if (mat[{x, y}] == '2') {
    visited[{x, y}] = true;
    vector<int> valid = {0, 0, 0, 0};
    vector<pair<int, int>> points;
    for (int i = 0; i < 4; ++i) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if (!check(xx, yy)) valid[i] = true;
      points.push_back({xx, yy});
    }

    if (valid[0] && valid[1] && valid[2] || valid[3] && valid[1] && valid[2] ||
        valid[0] && valid[3] && valid[2] || valid[0] && valid[3] && valid[1] ||
        valid[0] && valid[1] && !check(x - 1, y + 1) ||
        valid[1] && valid[2] && !check(x + 1, y + 1) ||
        valid[2] && valid[3] && !check(x + 1, y - 1) ||
        valid[0] && valid[3] && !check(x - 1, y - 1) ) {
      ok += true;
    }

    good += 1;
    return;
  }

  if (!visited[{x, y}]) {
    visited[{x, y}] = true;


    vector<int> valid = {0, 0, 0, 0};
    vector<pair<int, int>> points;
    for (int i = 0; i < 4; ++i) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if (!check(xx, yy)) valid[i] = true;
      points.push_back({xx, yy});
    }

    if (valid[0] && valid[1] && valid[2] || valid[3] && valid[1] && valid[2] ||
        valid[0] && valid[3] && valid[2] || valid[0] && valid[3] && valid[1] ||
        valid[0] && valid[1] && !check(x - 1, y + 1) ||
        valid[1] && valid[2] && !check(x + 1, y + 1) ||
        valid[2] && valid[3] && !check(x + 1, y - 1) ||
        valid[0] && valid[3] && !check(x - 1, y - 1) ) {
      ok += true;
    }

    for (int i = 0; i < 4; ++i) {
      if (!valid[i]) continue;
      int xx = points[i].first;
      int yy = points[i].second;
      dfs(xx, yy);
    }
  }
}

int main() {
  int x, y, x2, y2;
  while (cin >> n >> m) {
    good = ok = 0;
    mat.clear();
    visited.clear();

    string s;
    for (int i = 0; i < n; ++i) {
      cin >> s;
      for (int j = 0; j < m; ++j) {
        mat[{i, j}] = s[j];
        if (s[j] == '1') {
          x = i;
          y = j;
        }

        if (s[j] == '2') {
          x2 = i;
          y2 = j;
        }

      }
    }

    dfs(x, y);

    int cnt = 0;
    for (int i = 0; i < 4; ++i) {
      int xx = x2 + dx[i];
      int yy = y2 + dy[i];

      if (!check(xx, yy) && visited[{xx, yy}]) {
        cnt ++;
      }
    }

    if (cnt > 1) ok += 1;
    for (int i = 0; i < 4; ++i) {
      int xx = x2 + dx[i];
      int yy = y2 + dy[i];

      if (!check(xx, yy) && !visited[{xx, yy}]) {
        dfs(xx, yy);
        break;
      }
    }

    cout << (ok && good ? "YES" : "NO") << endl;
  }
  return 0;
}
