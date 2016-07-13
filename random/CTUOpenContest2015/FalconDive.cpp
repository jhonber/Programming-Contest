#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

bool check (int x, int y, int &n, int &m) {
  return x < 0 || x >= n || y < 0 || y >= m;
}

int main() {
  int n, m;
  string s;
  char c;
  while (cin >> n >> m >> s) {
    if (!n) break;

    c = s[1];
    char mat[n][m];
    char mat2[n][m];

    int x1, y1, x2, y2, f = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> mat[i][j];

        if (f && mat[i][j] == c) {
          f = false;
          x1 = i;
          y1 = j;
        }
      }
    }

    f = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> mat2[i][j];

        if (f && mat2[i][j] == c) {
          f = false;
          x2 = i;
          y2 = j;
        }
      }
    }

    int dx = x2 - x1;
    int dy = y2 - y1;

    dx *= 2;
    dy *= 2;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (mat2[i][j] == c) {
          mat2[i][j] = mat[i][j];
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (mat[i][j] == c) {
          if (!check(i + dx, j + dy, n, m))
            mat2[i + dx][j + dy] = c;
        }

      }
    }


    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << mat2[i][j];
      }
      cout << endl;
    }

    cout << endl;
  }

  return 0;
}
