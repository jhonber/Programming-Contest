#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

const int mx = 1000100;

int n;
vector<int> v(mx);
vector<int> G[mx];
vector<int> in[mx];

void solve(int x) {
  queue<int> Q;
  Q.push(x);
  vector<int> visited(n, 0);
  visited[x] = true;

  int ans = -INT_MAX;
  while (!Q.empty()) {
    int cur = Q.front(); Q.pop();
    ans = max(ans, cur);

    for (int i = 0; i < G[cur].size(); ++i) {
      int v = G[cur][i];
      if (!visited[v]) {
        Q.push(v);
        visited[v] = true;
      }
    }
  }

  cout << ans << endl;
}

int main() { IO
  while (cin >> n) {
    if (!n) break;

    map<int, vector<int>> mapa;
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      mapa[i - v[i]].push_back(i);
    }


    for (int i = 0; i < n; ++i) {
      int x = v[i] + i;
      for (int j = 0; j < mapa[x].size(); ++j) {
        int cur = mapa[x][j];
        G[i].push_back(cur);
        G[cur].push_back(i);
        in[cur].push_back(i);
        in[i].push_back(cur);

        for (int k = 0; k < in[i].size(); ++k) {
          int other = in[i][k];
          if (other < i) {
            G[other].push_back(cur);
            G[cur].push_back(other);
          }
        }
      }
    };

    solve(0);
    mapa.clear();
    for (int i = 0; i < n; ++i) G[i].clear();
    for (int i = 0; i < n; ++i) in[i].clear();
  }

  return 0;
}
