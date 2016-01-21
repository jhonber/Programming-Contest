#include<bits/stdc++.h>
using namespace std;


int mat[10][10];
bool check (int x, int y) {
  for (int i = x, j = y;  i <= 8 && j <= 8; ++i, ++j) {
    if (mat[i][j]) return true;
  }

  for (int i = x, j = y;  i >= 1 && j >= 1; --i, --j) {
    if (mat[i][j]) return true;
  }

  for (int i = x, j = y;  i >= 1 && j <= 8; --i, ++j) {
    if (mat[i][j]) return true;
  }

  for (int i = x, j = y;  i <= 8 && j >= 1; ++i, --j) {
    if (mat[i][j]) return true;
  }

  for (int i = x;  i <= 8; ++i) {
    if (mat[x][i]) return true;
  }

  for (int i = x;  i >= 1; --i) {
    if (mat[x][i]) return true;
  }

  for (int i = x;  i <= 8; ++i) {
    if (mat[i][y]) return true;
  }

  for (int i = x;  i >= 1; --i) {
    if (mat[i][y]) return true;
  }



  return false;
}

int main () {
  int x, y, x2, y2;
  while (cin >> x >> y >> x2 >> y2) {
    if (!x && !y && !x2 && !y2) break;
    memset(mat, 0, sizeof mat);
    mat[x2][y2] = true;
    if (x == x2 && y == y2) {
      cout << 0 << endl;
    }
    else if (check (x, y)) {
      cout << 1 << endl;
    }
    else {
      cout << 2 << endl;
    }
  }
  return 0;
}