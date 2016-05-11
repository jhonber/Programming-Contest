// http://codeforces.com/contest/660/problem/B

#include<bits/stdc++.h>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(null);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, m;
  while (cin >> n >> m) {
    int cnt = 1;
    int mat[n][4];
    memset(mat, 0, sizeof mat);

    for (int i = 0; i < n && cnt <= m; ++i) {
      mat[i][0] = cnt ++;
      if (cnt > m) break;
      mat[i][3] = cnt ++;
    }

    for (int i = 0; i < n && cnt <= m; ++i) {
      mat[i][1] = cnt ++;
      if (cnt > m) break;
      mat[i][2] = cnt ++;
    }

    for (int i = 0; i < n; ++i) {
      if (mat[i][1]) cout << mat[i][1] << " ";
      if (mat[i][0]) cout << mat[i][0] << " ";
      if (mat[i][2]) cout << mat[i][2] << " ";
      if (mat[i][3]) cout << mat[i][3] << " ";
    }

  }

  return 0;
}