#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

bool cycle (int i, vector<vector<int>> &G, vector<int> &color) {
  if (color[i] == 1) return true;

  bool found = false;
  if (color[i] == 0) {
    color[i] = 1;

    for (int j = 0; j < G[i].size(); ++j) {
      found = cycle(G[i][j], G, color);
      if (found) return found;
    }

    color[i] = 2;
  }

  return found;
}

int main() {
  int n;

  while (cin >> n) {
    int mmx = 2 * n + 10;
    vector<vector<int>> G(mmx);
    vector<int> color(mmx, 0);

    map<string, int> mapa;
    int ind = 0;
    for (int i = 0; i < n; ++i) {
      string a, dir, b;
      cin >> a >> dir >> b;

      int u, v;
      if (!mapa.count(a)) {
        mapa[a] = ind ++;
      }
      u = mapa[a];

      if (!mapa.count(b)) {
        mapa[b] = ind ++;
      }
      v = mapa[b];

      if (dir == ">")
        G[u].push_back(v);
      else
        G[v].push_back(u);

    }

    int found = false;
    for (int i = 0; i < mmx; ++i) {
      if (color[i]) continue;
      bool ans = cycle(i, G, color);
      if (ans) {
        found = true;
        break;
      }
    }

    cout << (found ? "impossible" : "possible") << endl;
  }

  return 0;
}
