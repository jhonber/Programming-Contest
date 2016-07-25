// http://codeforces.com/contest/699/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, m;
  while (cin >> n >> m) {

    int cnt = 0;
    char mat[n][m];
    vector<int> rows(n, 0);
    vector<int> cols(m, 0);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> mat[i][j];
        if (mat[i][j] == '*') {
          rows[i] ++;
          cols[j] ++;
          cnt ++;
        }
      }
    }

    int x, y;
    int found = false;
    for (int i = 0; i < n && !found; ++i) {
      for (int j = 0; j < m && !found; ++j) {
        int tot = rows[i] + cols[j];
        if (mat[i][j] == '*') tot --;
        if (tot == cnt) {
          found = true;
          x = i + 1; y = j + 1;
          break;
        }
      }
    }

    if (!found) cout << "NO" << endl;

    else cout << "YES" << endl << x << " " << y << endl;

  }
  return 0;
}