#include<bits/stdc++.h>
using namespace std;

int size(long long x) {
  int s = 0;
  while (x > 0) {
    s ++;
    x /= 10;
  }
  return s;
}

string fix(long long x, int size) {
  string s;
  while (x > 0) {
    s.push_back((x % 10) + '0');
    x /= 10;
  }

  reverse(s.begin(), s.end());

  while (s.size() < size) s = " " + s;
  return s;
}

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;
    long long k = 1;
    long long mat[n + 10][n + 10];

    int mx = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        mat[i][j] = k << j;
        mx = max(size(mat[i][j]), mx);
      }
      k *= 2LL;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (j > 0) cout << " ";
        cout << fix(mat[i][j], mx);
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}