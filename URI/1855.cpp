#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, m;
  cin >> m >> n;

  char mat[n][m];
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) {
      mat[i][j] = s[j];
    }
  }

  int visited[n][m];
  memset(visited, 0, sizeof visited);

  int good = true;
  int x = 0, y = 0;
  while (true) {
    if (mat[x][y] == '*') break;

    if (mat[x][y] == '.' || visited[x][y] || x > n || y > m || x < 0 || y < 0) {
      good = false;
      break;
    }
    visited[x][y] = true;

    if (mat[x][y] == '>') {
      y ++;
      while (y < m && mat[x][y] == '.') {
        visited[x][y] = true;
        y ++;
      }
    }
    else if (mat[x][y] == '<') {
      y --;
      while (y > 0 && mat[x][y] == '.') {
        visited[x][y] = true;
        y --;
      }
    }
    else if (mat[x][y] == '^') {
      x --;
      while (x > 0 && mat[x][y] == '.') {
        visited[x][y] = true;
        x --;
      }
    }
    else {
      x ++;
      while (x < n && mat[x][y] == '.') {
        visited[x][y] = true;
        x ++;
      }
    }
  }

  cout << (good ? "*" : "!") << endl;
  return 0;
}
