#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
const int inf = 77777;

int solve (string x, map<string, vector<string>> &G) {
  map<string, int> visited;
  queue<pair<string, int>> Q;
  Q.push({x, 0});
  visited[x] = true;

  while (!Q.empty()) {
    pair<string, int> cur = Q.front(); Q.pop();
    if (cur.first == "*") return cur.second;

    for (int i = 0; i < G[cur.first].size(); ++i) {
      string v = G[cur.first][i];
      if (!visited[v]) {
        visited[v] = true;
        Q.push({v, cur.second + 1});
      }
    }
  }

  return inf;
}

int main() {
  int n, m;
  cin >> n >> m;

  map<string, vector<string>> G;
  for (int i = 0; i < m; ++i) {
    string a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  int ans = 0;
  ans += solve("Entrada", G);
  ans += solve("Saida", G);

  cout << ans << endl;
  return 0;
}