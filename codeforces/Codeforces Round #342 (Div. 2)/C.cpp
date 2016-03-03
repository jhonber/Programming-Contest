// http://codeforces.com/contest/625/problem/C

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, k;
  cin >> n >> k;

  int mat[n][n];

  int cnt = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j + 1 < k; ++j) mat[i][j] = cnt ++;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = k - 1; j < n; ++j) mat[i][j] = cnt ++;
  }

  int tot = 0;
  for (int i = 0; i < n; ++i) {
    tot += mat[i][k - 1];
  }

  cout << tot << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}