#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n; n ++;

  bool mat[n + 100][n + 100];
  memset(mat, 0, sizeof mat);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> mat[i][j];
    }
  }

  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n - 1; ++j) {
      int tot = mat[i][j];
      tot += mat[i][j + 1];
      tot += mat[i + 1][j];
      tot += mat[i + 1][j + 1];

      cout << (tot >= 2 ? 'S' : 'U');
    }
    cout << endl;
  }

  return 0;
}