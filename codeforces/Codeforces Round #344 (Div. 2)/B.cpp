// http://codeforces.com/contest/631/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

struct data {
  int a, b, c;
  data () {}
  data (int x, int y, int z) {
    a = x; b = y; c = z;
  }
};

int main() { IO
  int n, m, k;
  cin >> n >> m >> k;

  vector<data> v(k);

  for (int i = 0; i < k; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    v[i] = data(a, b, c);
  }

  int mat[n][m];
  memset(mat, 0, sizeof mat);

  vector<int> todo;
  map<pair<int, int>, bool> ready;

  for (int i = k - 1; i >= 0; --i) {
    data d = v[i];
    pair<int, int> cur = {d.a, d.b};
    if (!ready[cur]) {
      ready[cur] = true;
      todo.push_back(i);
    }
  }

  for (int i = todo.size() - 1; i >= 0; --i) {
    data d = v[todo[i]];
    if (d.a == 1) {
      for (int x = 0; x < m; ++x) mat[d.b - 1][x] = d.c;
    }
    else {
      for (int x = 0; x < n; ++x) mat[x][d.b - 1] = d.c;
    }
  }

  cout << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}