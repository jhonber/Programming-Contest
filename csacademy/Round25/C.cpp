// https://csacademy.com/contest/round-25/#task/rectangle-path
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MMAX = 1001;
int n, m;
int mat[MMAX][MMAX];
int pre[MMAX][MMAX];
int best[MMAX][MMAX];

void pre_sum () {
  for (int i = 0; i < m; ++i) {
    pre[0][i] = mat[0][i];
  }

  for (int i = 0; i < n ; ++i) {
    for (int j = 1; j < m; ++j) {
      pre[i][j] = mat[i][j] + pre[i][j - 1];
    }
  }

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      pre[i][j] += pre[i - 1][j];
    }
  }
}

int get_sum (int x, int y, int x2, int y2) {
  int sum = pre[x2][y2];

  if (x > 0) sum -= pre[x - 1][y2];
  if (y > 0) sum -= pre[x2][y - 1];
  if (x > 0 && y > 0) sum += pre[x - 1][y - 1];

  return sum;
}

bool bad (int r, int c, int h, int w) {
  bool ans = r < 0 || r >= n || c < 0 || c >= m || r + h >= n || c + w >= m;
  if (ans) return ans;
  int ans2 = get_sum(r, c, r + h, c + w);
  return ans2;
}

void solve (int h, int w, int r, int c, int r2, int c2) {
  queue<pair<int, int>> Q;
  Q.push({r, c});

  best[r][c] = 0;

  int dx[] = { 0, 0, -1, 1};
  int dy[] = {-1, 1,  0, 0};

  while (!Q.empty()) {
    pair<int, int> cur = Q.front(); Q.pop();

    if (cur.first == r2 && cur.second == c2) {
      cout << best[cur.first][cur.second] << endl;
      return;
    }

    for (int i = 0; i < 4; ++i) {
      int x = dx[i] + cur.first;
      int y = dy[i] + cur.second;

      if (best[x][y] == -1 && !bad(x, y, h, w)) {
        Q.push({x, y});
        best[x][y] = best[cur.first][cur.second] + 1;
      }
    }
  }

  cout << -1 << endl;
}

int main() { IO
  cin >> n >> m;

  memset(best, -1, sizeof best);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> mat[i][j];
    }
  }

  int h, w, r, c, r2, c2;
  cin >> h >> w >> r >> c >> r2 >> c2;
  h --; w --; r --; c --; r2 --; c2 --;

  pre_sum();
  solve(h, w, r, c, r2, c2);

  return 0;
}
