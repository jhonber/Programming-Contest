// http://codeforces.com/contest/339/problem/D

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

struct query {
  int a, b;
  query(){}
  query(int a_, int b_) {
    a = a_;
    b = b_;
  }
};

int main () { IO
  int n, m;
  cin >> n >> m;

  int lim = 1 << n;
  int mat[n + 5][lim];

  for (int i = 0; i < lim; ++i) cin >> mat[0][i];

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < lim; ++j) {
      if (i % 2) {
        mat[i][j] = mat[i - 1][2 * j] | mat[i - 1][2 * j + 1];
      }
      else {
        mat[i][j] = mat[i - 1][2 * j] ^ mat[i - 1][2 * j + 1];
      }
    }
  }

  vector<query> queries(m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b; a --;
    queries[i] = query(a, b);
  }

  for (int i = 0; i < m; ++i) {
    int a = queries[i].a;
    int b = queries[i].b;
    mat[0][a] = b;

    int j = a;
    for (int i = 1; i <= n; ++i) {
      j /= 2;
      if (i % 2) {
        mat[i][j] = mat[i - 1][2 * j] | mat[i - 1][2 * j + 1];
      }
      else {
        mat[i][j] = mat[i - 1][2 * j] ^ mat[i - 1][2 * j + 1];
      }
    }

    cout << mat[n][0] << endl;
  }

  return 0;
}