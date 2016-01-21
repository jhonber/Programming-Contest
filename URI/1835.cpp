#include<bits/stdc++.h>
using namespace std;
 
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x)cout << #x << " = " << (x) << endl;
 
vector<int>G[111];
int visited[111];
 
void dfs(int i) {
  if (!visited[i]) {
    visited[i] = true;
    for (int j = 0; j < G[i].size(); ++j) {
      dfs(G[i][j]);
    }
  }
}
 
int main() {
  int n, m, t;
  cin >> t;
 
  for (int TC = 1; TC <= t; ++TC) {
    cin >> n >> m;
    int tot = 0;
    for (int i = 0; i < 111; ++i) G[i].clear();
    memset(visited, 0, sizeof visited);
 
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      G[a].push_back(b);
      G[b].push_back(a);
    }
 
    for (int i = 1; i <= n; ++i) {
      if (!visited[i]) {
        dfs(i);
        tot ++;
      }
    }
 
    tot --;
    if (!tot) cout << "Caso #" << TC << ": a promessa foi cumprida" << endl;
    else cout << "Caso #" << TC <<": ainda falta(m) " << tot << " estrada(s)" << endl;
  }
  return 0;
}
