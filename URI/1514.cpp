#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, m;
  while (cin >> n >> m) {
    if (!n) break;

    int mat[n][m];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> mat[i][j];
      }
    }

    int a, b, c, d;

    a = true;
    for (int i = 0; i < n; ++i) {
      int cnt = 0;
      for (int j = 0; j < m; ++j) {
        if (mat[i][j]) cnt ++;
      }

      if (cnt == m) a = false;
    }

    vector<int> v(m, 0);
    b = false;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (mat[i][j]) v[j] = 1;
      }
    }

    int tot = accumulate(v.begin(), v.end(), 0);
    if (tot == m) b = true;

    c = true;
    for (int j = 0; j < m; ++j) {
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
        if (mat[i][j]) cnt ++;
      }

      if (cnt == n) c = false;
    }

    d = true;
    for (int i = 0; i < n; ++i) {
      int cnt = 0;
      for (int j = 0; j < m; ++j) {
        if (mat[i][j]) cnt ++;
      }

      if (!cnt) d = false;
    }

    cout << (a + b + c + d) << endl;
  }

  return 0;
}