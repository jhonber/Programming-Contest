#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, m, c;

  while (cin >> m >> n >> c) {
    if (!n) break;

    int mat[n][m];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> mat[i][j];
      }
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ) {
        if (mat[j][i] == 1) {
          int tot = 0;
          while (j < n && mat[j][i] == 1) {
            tot ++;
            j ++;
          }

          ans += (tot >= c ? 1 : 0);
        }
        else j ++;
      }
    }

    cout << ans << endl;
  }

  return 0;
}