#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " " << (x) << endl;

int main() {
  int t;
  cin >> t;

  int TC = 4;
  while (t --> 0) {
    int n;
    cin >> n;

    if (TC > 4) cout << endl;
    cout << "Quadrado da matriz #" << TC++ << ":" << endl;

    string mat[n][n];
    unsigned long long x;

    stringstream ss;
    string tmp;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> x;
        x *= x;

        ss.clear();
        ss << x;
        ss >> tmp;
        mat[i][j] = tmp;
      }
    }

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      int mx = -INT_MAX;
      for (int j = 0; j < n; ++j) {
        mx = max((int)mat[j][i].size(), mx);
      }
      v[i] = mx;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        while ((int)mat[i][j].size() < v[j]) {
          mat[i][j] = " " + mat[i][j];
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      cout << mat[i][0];
      for (int j = 1; j < n; ++j) {
        cout << " " << mat[i][j];
      }
      cout << endl;
    }

  }

  return 0;
}