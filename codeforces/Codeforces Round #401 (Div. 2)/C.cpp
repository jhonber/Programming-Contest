// http://codeforces.com/contest/777/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

struct R {
  int l, r;
  R() {}
  R(int a, int b) {
    l = a;
    r = b;
  }

  bool operator < (const R &other) const {
    int x = l - r;
    int y = other.l - other.r;
    return x < y;
  }
};

int main() {
#ifdef ONLINE_JUDGE
  IO
#endif

  int n, m;
  cin >> n >> m;

  int mat[n][m];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> mat[i][j];
    }
  }

  vector<R> ranges;
  for (int c = 0; c < m; ++c) {
    int i = 0, j = 1;
    while (j < n) {
      while (j < n && mat[j - 1][c] <= mat[j][c]) j ++;

      if (j - i > 1)
        ranges.push_back(R(i, j - 1));

      i = j;
      j ++;
    }
  }

  sort(ranges.begin(), ranges.end());

  int q, l, r;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    cin >> l >> r;
    l --; r--;

    int d = r - l;
    pair<int, int> cur = {l, r};
    bool ok = false;

    if (l == r) {
      ok = true;
    }
    else {
      for (int j = 0; j < ranges.size(); ++j) {
        int t = ranges[j].r - ranges[j].l;
        if (l >= ranges[j].l && r <= ranges[j].r) {
          ok = true;
          break;
        }

        if (t < d) {
          break;
        }
      }
    }

    cout << (ok ? "Yes" : "No") << endl;
  }

  return 0;
}