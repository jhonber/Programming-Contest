#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int f;
vector<int> G[33];
void solve (int i, vector<int> &visited, set<pair<int, int>> st, string tab) {
  if (!visited[i]) {
    visited[i] = true;
    tab += "  ";
    for (int j = 0; j < G[i].size(); ++j) {
      if (st.count({i, G[i][j]}) > 0) continue;
      st.insert({i, G[i][j]});

      cout << tab << i << "-" << G[i][j];
      if (!visited[G[i][j]]) cout << " pathR(G," << G[i][j] << ")" << endl;
      else cout << endl;
      f = true;
      solve(G[i][j], visited, st, tab);
    }
  }
}

int main() {
  int t;
  cin >> t;

  int TC = 1;
  int n, m;
  while (t --> 0) {
    cin >> n >> m;

    for (int i = 0; i < 33; ++i) G[i].clear();

    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      G[a].push_back(b);
    }

    for (int i = 0; i < 33; ++i) {
      sort(G[i].begin(), G[i].end());
    }

    cout << "Caso " << TC ++ << ":" << endl;
    vector<int> visited(n, 0);
    set<pair<int, int>> st;
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        f = false;
        solve(i, visited, st, "");
        if (f)
          cout << endl;
      }
    }
  }
  return 0;
}