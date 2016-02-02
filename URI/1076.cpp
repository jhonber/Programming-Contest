#include<bits/stdc++.h>
using namespace std;

vector<int> G[111];
void dfs(int i, vector<int> &visited, int &tot) {
  if (!visited[i]) {
    visited[i] = true;
    tot ++;
    for (int j = 0; j < G[i].size(); ++j) {
      dfs(G[i][j], visited, tot);
    }
  }
}

int main() {
  int TC;
  cin >> TC;

  for (int i = 0; i < TC; ++i) {
    int n, m, init;
    cin >> init >> n >> m;

    for (int i = 0; i < 111; ++i) G[i].clear();
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      G[a].push_back(b);
      G[b].push_back(a);
    }

    vector<int> visited(111, 0);
    int tot = 0;
    dfs(init, visited, tot);
    cout << (tot - 1) * 2 << endl;
  }

  return 0;
}
