// http://codeforces.com/contest/761/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

const int inf = 1e6;

int main() {
  int n, m;
  cin >> n >> m;

  string s;
  vector<string> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> s;
    v[i] = s;
  }

  int mat[n][3];

  for (int i = 0; i < n; ++i) {
    int best[] = {inf, inf, inf};
    for (int j = 0; j < m; ++j) {
      if (isdigit(v[i][j])) {
        best[0] = min(best[0], min(j, m - j));
      }
      else if (isalpha(v[i][j])) {
        best[1] = min(best[1], min(j, m - j));
      }
      else {
        best[2] = min(best[2], min(j, m - j));
      }
    }

    mat[i][0] = best[0];
    mat[i][1] = best[1];
    mat[i][2] = best[2];
  }

  int ans = 3 * inf;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        if (i != j && j != k && i != k) {
          int ind[] = {0, 1, 2};
          do {
            int tot = 0;
            tot = mat[i][ind[0]] + mat[j][ind[1]] + mat[k][ind[2]];
            ans = min(tot, ans);
          }
          while (next_permutation(ind, ind + 3));
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}