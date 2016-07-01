// http://codeforces.com/contest/688/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

vector<int> color(100100, -1);
vector<int> G[100100];
vector<int> a, b;

bool dfs (int x) {
  color[x] = 0;
  queue<int> Q;
  Q.push(x);

  while (!Q.empty()) {
    int cur = Q.front(); Q.pop();
    if (color[cur]) a.push_back(cur);
    else b.push_back(cur);

    for (int i = 0; i < G[cur].size(); ++i) {
      int v = G[cur][i];
      if (color[v] == -1) {
        color[v] = !color[cur];
        Q.push(v);
      }
      else if (color[cur] == color[v]) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  int good = true;
  for (int i = 1; i <= n; ++i) {
    if (color[i] != -1) continue;
    int tmp = dfs(i);
    if (!tmp) {
      good = false;
      break;
    }
  }

  if (!good) cout << -1 << endl;
  else {
    cout << a.size() << endl;
    for (auto j : a) cout << j << " "; cout << endl;

    cout << b.size() << endl;
    for (auto j : b) cout << j << " "; cout << endl;
  }

  return 0;
}