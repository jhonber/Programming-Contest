// http://codeforces.com/contest/659/problem/E

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

void dfs(int i, vector<int> &visited, vector<vector<int>> &G) {
  if (!visited[i]) {
    visited[i] = true;
    for (int j = 0; j < G[i].size(); ++j) {
      int cur = G[i][j];
      dfs(cur, visited, G);
    }
  }
}

/** Krustal implementation
 *  Complexity: O(E log V)
 **/

const int mx = 100100;

struct edge {
  int start, end, weight;
  edge(){} edge(int start, int end, int weight) : start(start), end(end), weight(weight) {}
  bool operator < (const edge &that) const {
    // Change < by > to find maximum spanning tree
    return weight > that.weight;
  }
};

/** Begin union find
 *  Complexity: O(m log n) where m is the number of the operation
 *              and n are the number of objects, in practice is almost O(m)
 **/
int p[mx];

void init_set (int &n) {
  for (int i = 0; i <= n; ++i) p[i] = i;
}

int find_set (int x) {
  return p[x] == x ? p[x] : p[x] = find_set(p[x]);
}

void join (int x, int y) {
  p[find_set(x)] = find_set(y);
}
/**  End union find **/

/** e is a vector with all edges of the graph
 *  return graph of MST
 **/
int krustal (vector<edge> &e, vector<vector<int>> &G, int &n) {
  init_set(n);

  vector<int> visited(n, 0);
  for (int i = 0 ; i < e.size(); ++i) {
    int u = e[i].start;
    int v = e[i].end;
    if (find_set(u) != find_set(v)) {
      join(u, v);
    }
    else {
      dfs(u, visited, G);
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (visited[i]) continue;
    ans ++;
    dfs(i, visited, G);
  }

  return ans;
}


int main() {
  int n, m;
  cin >> n >> m;

  vector<edge> G;
  vector<vector<int>> G2(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b; a --; b --;

    edge e;
    e.start = a;
    e.end = b;
    e.weight = 0;

    G.push_back(e);
    G2[a].push_back(b);
    G2[b].push_back(a);
  }

  cout << krustal(G, G2, n);
  return 0;
}