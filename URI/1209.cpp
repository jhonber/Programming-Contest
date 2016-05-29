#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() { IO
  int n, m, k;

  while (cin >> n >> m >> k) {
    vector<int> G[n];
    vector<int> inc(n, 0);

    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b; a--; b--;

      G[a].push_back(b);
      G[b].push_back(a);
      inc[a] ++;
      inc[b] ++;
    }

    set<int> paila;
    int found = true;
    while (found) {
      found = false;
      for (int i = 0; i < n; ++i) {
        if (inc[i] < k && paila.count(i) == 0) {
          paila.insert(i);
          for (int j = 0; j < G[i].size(); ++j) {
            inc[G[i][j]] --;
          }

          found = true;
        }
      }
    }

    if (paila.size() == n) {
      cout << 0 << endl;
      continue;
    }

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      if (paila.count(i) == 0) ans.push_back(i + 1);
    }

    cout << ans[0];
    for (int i = 1; i < ans.size(); ++i) cout << " " << ans[i]; cout << endl;
  }

  return 0;
}