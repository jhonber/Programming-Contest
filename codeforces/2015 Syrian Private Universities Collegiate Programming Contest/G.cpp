#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int n, m;
bool check(int x, int y) {
  return x < 0 || x >= n || y < 0 || y >= m;
}

int main() {
  int t;
  cin >> t;
  while (t --> 0) {
    cin >> n >> m;

    char mat[n][m];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> mat[i][j];
      }
    }

    int found = false;
    for (int i = 0; i < n && !found; ++i) {
      for (int j = 0; j < m; ++j) {
        if (mat[i][j] == 'p') {
          if (!check(i, j + 2) && mat[i][j + 1] == 'i' && mat[i][j + 2] == 'e') {
            found = true;
            break;
          }

          if (!check(i + 2, j) && mat[i + 1][j] == 'i' && mat[i + 2][j] == 'e') {
            found = true;
            break;
          }

          if (!check(i + 2, j + 2) && mat[i + 1][j + 1] == 'i' && mat[i + 2][j + 2] == 'e') {
            found = true;
            break;
          }

          if (!check(i + 2, j - 2) && mat[i + 1][j - 1] == 'i' && mat[i + 2][j - 2] == 'e') {
            found = true;
            break;
          }
        }
        if (mat[i][j] == 'e') {
          if (!check(i, j + 2) && mat[i][j + 1] == 'i' && mat[i][j + 2] == 'p') {
            found = true;
            break;
          }

          if (!check(i + 2, j) && mat[i + 1][j] == 'i' && mat[i + 2][j] == 'p') {
            found = true;
            break;
          }

          if (!check(i + 2, j + 2) && mat[i + 1][j + 1] == 'i' && mat[i + 2][j + 2] == 'p') {
            found = true;
            break;
          }

          if (!check(i + 2, j - 2) && mat[i + 1][j - 1] == 'i' && mat[i + 2][j - 2] == 'p') {
            found = true;
            break;
          }
        }
      }
    }

    cout << (found ? "Cutie Pie!" : "Sorry Man") << endl;
  }
  return 0;
}
