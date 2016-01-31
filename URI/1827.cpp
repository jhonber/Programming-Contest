#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    int mat[n][n];
    memset(mat, 0, sizeof mat);

    for (int i = 0; i < n; ++i) {
      mat[i][i] = 2;
    }

    for (int i = 0, j = n - 1; i < n; ++i, --j) {
      mat[i][j] = 3;
    }

    int one = n / 3;
    int size = n - (2 * one);

    for (int i = one, ii = 0 ; ii < size; ++i, ++ii) {
      for (int j = one, jj = 0; jj < size; ++j, ++jj) {
        mat[i][j] = 1;
      }
    }

    int mid = n / 2;
    mat[mid][mid] = 4;


    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        printf("%d", mat[i][j]);
      }
      printf("\n");
    }
    printf("\n");
  }

  return 0;
}
