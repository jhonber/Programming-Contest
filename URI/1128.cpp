#include<bits/stdc++.h>
using namespace std;

vector<int> G[2222];
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
  int n, m;
  while (cin >> n >> m) {
    if (n + m == 0) break;
    for (int i = 0; i < 2222; ++i) G[i].clear();

    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;

      if (c == 1) {
        G[a].push_back(b);
      }
      else {
        G[a].push_back(b);
        G[b].push_back(a);
      }
    }

    int good = true;
    for (int i = 1; i <= n; ++i) {
      vector<int> visited(2222, 0);
      int tot = 0;
      dfs(i, visited, tot);
      if (tot != n) {
        good = false;
        break;
      }
    }

    cout << (good ? 1 : 0) << endl;
  }
  return 0;
}
