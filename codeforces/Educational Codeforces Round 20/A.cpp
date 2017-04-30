// http://codeforces.com/contest/803/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, k;
  while (cin >> n >> k) {
    bool mat[111][111];
    memset(mat, 0, sizeof mat);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j]) continue;
        int r = (i == j ? 1 : 2);
        if (r <= k) {
          k -= r;
          mat[i][j] = mat[j][i] = 1;
        }
      }
    }

    if (k > 0) cout << -1 << endl;
    else {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          cout << mat[i][j] << " ";
        }
        cout << endl;
      }
    }
  }

  return 0;
}