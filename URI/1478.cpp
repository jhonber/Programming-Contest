#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

string f(int x) {
  stringstream ss;
  ss << x;

  string out;
  ss >> out;

  while (out.size() < 3) {
    out = " " + out;
  }

  return out;
}

int main() {
  int n;

  while (cin >> n) {
    if (!n) break;

    int mat[n][n];
    for (int j = 0; j < n; ++j) {
      int i = 0;
      int k = j;
      while (i < n && k < n) {
        mat[i][k] = j + 1;
        mat[k][i] = j + 1;
        i ++;
        k ++;
      }
    }

    for (int i = 0; i < n; ++i) {
      cout << f(mat[i][0]);
      for (int j = 1; j < n; ++j) {
        cout << " " << f(mat[i][j]);
      }
      cout << endl;
    }

    cout << endl;
  }

  return 0;
}
