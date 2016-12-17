#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, m;
  cin >> n >> m;

  n ++;
  m ++;

  int mat[n + 100][m + 100];
  memset(mat, 0, sizeof mat);

  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      cin >> mat[i][j];
    }
  }

  int dx[] = {-1, -1, -1, 0, 1, 1,  1, 0};
  int dy[] = {-1,  0,  1, 1, 1, 0, -1, -1};

  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      int tot = 0;
      for (int k = 0; k < 8; ++k) {
        if (mat[i + dx[k]][j + dy[k]] == 7) tot ++;
      }

      if (tot == 8 && mat[i][j] == 42) {
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }

  cout << "0 0" << endl;
  return 0;
}