// http://codeforces.com/contest/579/problem/B

#include<bits/stdc++.h>
using namespace std;

struct p {
  int x, y, c;
};

int main() {
  int n;
  cin >> n;

  n *= 2;
  map< int, pair<int, int> > mapa;


  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      int t;
      cin >> t;
      mapa[t] = make_pair(i, j);
    }
  }

  map< int, pair<int, int> > :: reverse_iterator it = mapa.rbegin();

  vector<int> ans(n, 0);
  while (it != mapa.rend()) {
    pair<int, int> cur = it -> second;
    int x = cur.first;
    int y = cur.second;

    if (!ans[y] && !ans[x]) {
      ans[y] = x + 1;
      ans[x] = y + 1;
    }

    it ++;
  }

  for (int i = 0; i < n; ++i) cout << ans[i] << " ";
  return 0;
}