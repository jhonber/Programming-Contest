// http://codeforces.com/contest/629/problem/A

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  long long ans = 0;
  char mat[n][n];
  for (int i = 0; i < n; ++i) {
    long long row = 0;
    for (int j = 0; j < n; ++j) {
      cin >> mat[i][j];
      if (mat[i][j] == 'C') row ++;
    }

    if (row > 1) {
      row --;
      ans += (row * (row + 1)) / 2LL;
    }
  }

  for (int i = 0; i < n; ++i) {
    long long col = 0;
    for (int j = 0; j < n; ++j) {
      if (mat[j][i] == 'C') col ++;
    }

    if (col> 1) {
      col --;
      ans += (col * (col + 1)) / 2LL;
    }

  }

  cout << ans;
  return 0;
}