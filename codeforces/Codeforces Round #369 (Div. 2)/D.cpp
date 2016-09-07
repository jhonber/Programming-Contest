// http://codeforces.com/contest/711/problem/D

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

const int mx = 200100;
const int mod = 1e9 + 7;

long long mpow (long long b, long long e, long long mod) {
  long long ans = 1;
  while (e) {
    if (e & 1) ans = (ans * b) % mod;
    b = (b * b) % mod;
    e >>= 1;
  }
  return ans;
}

void dfs (int i, vector<vector<int>> &G, vector<int> &visited, int &s) {
  if (!visited[i]) {
    visited[i] = true;
    s ++;

    for (int j = 0; j < G[i].size(); ++j) {
      dfs(G[i][j], G, visited, s);
    }
  }
}

struct edge {
  int start, end, weight;
  edge(){} edge(int start, int end, int weight) : start(start), end(end), weight(weight) {}
  bool operator < (const edge &that) const {
    // Change < by > to find maximum spanning tree
    return weight > that.weight;
  }
};

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

void solve (vector<edge> &e, vector<vector<int>> &G, int &n) {
  init_set(n);

  long long ans = 1;
  int tot = 0;

  vector<int> visited(n, 0);
  for (int i = 0 ; i < e.size(); ++i) {
    int u = e[i].start;
    int v = e[i].end;
    if (find_set(u) != find_set(v)) {
      join(u, v);
    }
    else {
      int size = 0;
      dfs(u, G, visited, size);
      long long t = (mpow(2, size, mod) - 2 + mod) % mod;
      ans = (ans * t) % mod;
    }
  }

  int others = 0;
  for (int i = 0; i < n; ++i) others += !visited[i];

  ans = (mpow(2, others, mod) * ans) % mod;
  cout << ans << endl;
}

int main() {
  int n;
  cin >> n;

  vector<edge> G;
  vector<vector<int>> G2(n);
  for (int i = 0; i < n; ++i) {
    int b;
    cin >> b; b --;

    edge e;
    e.start = i;
    e.end = b;

    G.push_back(e);
    G2[i].push_back(b);
  }

  solve(G, G2, n);
  return 0;
}