#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

void left (int x, int &y, vector<string> &mat) {
  char c = mat[x][y];
  while (y - 1 >= 0 && mat[x][y - 1] == '?') {
    mat[x][y - 1] = c;
    y --;
  }
}

void right (int x, int &y, int c, vector<string> &mat) {
  char ca = mat[x][y];
  while (y + 1 < c && mat[x][y + 1] == '?') {
    mat[x][y + 1] = ca;
    y ++;
  }
}

void up (int x, int y, int len, char c, vector<string> &mat) {
  vector<string> mat2 = mat;
  while (x >= 0) {
    bool f = true;
    for (int i = 0; i < len && x - 1 >= 0; ++i) {
      if (mat[x - 1][i + y] == '?') {
        mat2[x - 1][i + y] = c;
      }
      else f = false;
    }

    if (x - 1 >= 0 && f) mat[x - 1] = mat2[x - 1];
    if (!f) break;
    x --;
  }
}

void down (int x, int y, int len, int r, char c, vector<string> &mat) {
  vector<string> mat2 = mat;
  while (x < r) {
    bool f = true;
    for (int i = 0; i < len && x + 1 < r; ++i) {
      if (mat[x + 1][i + y] == '?') {
        mat2[x + 1][i + y] = c;
      }
      else f = false;
    }

    if (x + 1 < r && f) mat[x + 1] = mat2[x + 1];
    if (!f) break;
    x ++;
  }
}

int main() {
  int t, r, c, TC = 1;
  cin >> t;

  while (t --> 0) {
    cin >> r >> c;

    vector<string> mat(r);
    for (int i = 0; i < r; ++i) cin >> mat[i];

    set<char> ready;
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (mat[i][j] != '?' && ready.count(mat[i][j]) == 0) {
          ready.insert(mat[i][j]);
          int y1 = j;
          int y2 = j;

          left(i, y1, mat);
          right(i, y2, c, mat);

          int len = y2 - y1 + 1;
          up(i, y1, len, mat[i][j], mat);
          down(i, y1, len, r, mat[i][j], mat);
        }
      }
    }

    cout << "Case #" << TC ++ << ":" << endl;
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        cout << mat[i][j];
      }
      cout << endl;
    }
  }

  return 0;
}
