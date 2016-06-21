#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

int main() {
  int n, m, a, b;
  while (cin >> n >> m) {
    if (!n) break;
    char mat[n][m];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> mat[i][j];
      }
    }

    cin >> a >> b;

    int sizef = a / n;
    int sizec = b / m;
    for (int i = 0; i < n; ++i) {
      string line;
      for (int j = 0; j < m; ++j) {
        char cur = mat[i][j];
        for (int l = 0; l < sizec; ++l) {
          cout << cur;
          line.push_back(cur);
        }
      }

      cout << endl;
      for (int k = 0; k + 1 < sizef; ++k) {
        cout << line << endl;
      }
    }
    cout << endl;
  }

  return 0;
}