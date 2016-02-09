#include<bits/stdc++.h>
using namespace std;

vector<int> visited(33, 0);
vector<int> G[33];

void dfs(int i, vector<int> &path) {
  if (!visited[i]) {
    visited[i] = true;
    path.push_back(i);
    for (int j = 0; j < G[i].size(); ++j) {
      dfs(G[i][j], path);
    }
  }
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    cout << "Case #" << i + 1 << ":" << endl;
    int n, m;
    cin >> n >> m;

    for (int j = 0; j < 33; ++j) G[j].clear();
    for (int j = 0; j < 33; ++j) visited[j] = 0;
    for (int j = 0; j < m; ++j) {
      char a, b;
      cin >> a >> b;
      G[a - 'a'].push_back(b - 'a');
      G[b - 'a'].push_back(a - 'a');
    }

    int tot = 0;
    for (int j = 0; j < n; ++j) {
      if (!visited[j]) {
        vector<int> ans;
        dfs(j, ans);
        sort(ans.begin(), ans.end());
        for (int k = 0; k < ans.size(); ++k) cout << (char)(ans[k] + 'a') << ",";
        if (ans.size() > 0) {
          cout << endl;
          tot ++;
        }
      }
    }
    cout << tot << " connected components" << endl << endl;
  }
  return 0;
}