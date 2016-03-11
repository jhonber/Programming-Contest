#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    char mat[n][n];
    memset(mat, '3', sizeof mat);
    for (int i = 0; i < n; ++i) {
      mat[i][i] = '1';
    }

    for (int i = 0, j = n - 1; i < n; ++i, --j) {
      mat[i][j] = '2';
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << mat[i][j];
      }
      cout << endl;
    }

  }
  return 0;
}
