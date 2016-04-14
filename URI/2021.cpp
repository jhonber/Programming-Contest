#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, m, q;
  while (cin >> m >> n >> q) {
    if (!n) break;

    int mat[m][n];
    memset(mat, 0, sizeof mat);

    for (int i = 0; i < q; ++i) {
      int a;
      cin >> a; a --;
      for (int j = a%n; j < n; ++j) mat[i][j] = 1;
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j]) ans ++;
      }
    }

    cout << "Lights: " << ans << endl;
  }

  return 0;
}