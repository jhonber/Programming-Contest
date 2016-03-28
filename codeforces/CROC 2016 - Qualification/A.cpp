// http://codeforces.com/contest/644/problem/A

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  if (a * b < n) {
    cout << -1 << endl;
    return 0;
  }

  int mat[a][b];
  memset(mat, 0, sizeof mat);

  int cnt = 1;
  for (int i = 0; i < a; ++i) {
    for (int j = i % 2; j < b && cnt <= n; j += 2) {
      mat[i][j] = cnt;
      cnt += 2;
    }
  }

  cnt = 2;
  for (int i = 0; i < a; ++i) {
    for (int j = 0; j < b && cnt <= n; ++j) {
      if (!mat[i][j]) {
        mat[i][j] = cnt;
        cnt += 2;
      }
    }
  }


  for (int i = 0; i < a; ++i) {
    for (int j = 0; j < b; ++j) {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}