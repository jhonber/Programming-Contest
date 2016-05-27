#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

bool check(int x, int y, int n) {
  return x >= n || y >= n || x < 0 || y < 0;
}

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;
    int mat[n][n];
    memset(mat, 0, sizeof mat);

    int cur = n;
    int num = 1;
    for (int i = 0; i <= n / 2; ++i) {
      for (int j = i, c = 0; c < cur; ++j, ++c) {
        for (int k = i, c2 = 0; c2 < cur; ++k, ++c2) {
          mat[j][k] = num;
        }
      }

      num ++;
      cur -= 2;
    }

    stringstream ss;
    for (int i = 0; i < n; ++i) {
      string tmp1;
      ss.clear();
      ss << mat[i][0];
      ss >> tmp1;
      //cout << " " << mat[i][0];
      while (tmp1.size() < 3) tmp1 = " " + tmp1;
      cout << tmp1;
      for (int j = 1; j < n; ++j) {
        ss.clear();
        ss << mat[i][j];
        string tmp;
        ss >> tmp;
        while (tmp.size() < 3) tmp = " " + tmp;

        cout << " " << tmp;
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}