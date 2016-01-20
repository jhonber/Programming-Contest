#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int l;
int mat1[444][444];
int mat2[444][444];

int check(int f, int c, int a, int b, bool s) {
  int good = 0;
  for (int ii = 0, i = f; ii < l; ++ii, i += a) {
    for (int jj = 0, j = c; jj < l; ++jj, j += b) {
      if (!s) {
        if (abs(mat1[ii][jj] - mat2[i][j]) <= 100) good ++;
      }
      else {
        if (abs(mat1[ii][jj] - mat2[j][i]) <= 100) good ++;
      }
    }
  }

  return 100 * good;
}

double solve() {
  int ans = 0;
  ans = max(ans, check(0, 0, 1, 1, 0));
  ans = max(ans, check(0, 0, 1, 1, 1));
  ans = max(ans, check(0, l - 1, 1, -1, 1));
  ans = max(ans, check(0, l - 1, 1, -1,  0));
  ans = max(ans, check(l - 1, l - 1, -1, -1, 0));
  ans = max(ans, check(l - 1, l - 1, -1, -1, 1));
  ans = max(ans, check(l - 1, 0, -1, 1, 0));
  ans = max(ans, check(l - 1, 0, -1, 1, 1));

  return (double)ans / (l * l);
}

int main() {
  while (cin >> l) {
    if (!l) break;
    for (int i = 0; i < l; ++i) {
      for (int j = 0; j < l; ++j) {
        cin >> mat1[i][j];
      }
    }

    for (int i = 0; i < l; ++i) {
      for (int j = 0; j < l; ++j) {
        cin >> mat2[i][j];
      }
    }

    printf("%.2lf\n", solve());
  }

  return 0;
}