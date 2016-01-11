// http://codeforces.com/contest/616/problem/B

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(NULL); cie.tie(false);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, m;
  cin >> n >> m;

  int mat[n][m];
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j) {
      cin >> mat[i][j];
    }
  }

  int ans = -INT_MAX;

  for (int i = 0; i < n; ++i) {
    int mm = INT_MAX;
    for (int j = 0; j < m; ++j) {
      mm = min(mm, mat[i][j]);
    }

    ans = max(ans, mm);
  }

  cout << ans;
  return 0;
}