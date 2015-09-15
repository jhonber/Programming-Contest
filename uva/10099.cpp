// https://uva.onlinejudge.org/external/100/10099.pdf

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for (__typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }


/** Krustal implementation
 *  Complexity: O(E log V)
 **/

const int mx = 111;

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
vector< vector<edge> > krustal (vector<edge> &e, int &n) {
  double tot = 0;
  vector< vector<edge> > G(n + 1);
  sort(e.begin(), e.end());
  init_set(n);

  for (int i = 0 ; i < e.size(); ++i) {
    int u = e[i].start;
    int v = e[i].end;
    int w = e[i].weight;
    if (find_set(u) != find_set(v)) {
      join(u, v);
      G[u].push_back(edge(u, v, w));
      G[v].push_back(edge(v, u, w));
      tot += w;
    }
  }
  // return tot;
  return G;
}

vector<int> visited(mx);
int dfs (vector< vector<edge> > &G, int i, int &target, int &ans) {
  if (i == target) return true;

  int reachable = false;
  if (!visited[i]) {
    visited[i] = true;
    for (int j = 0; j < G[i].size(); ++j) {
      int next  = G[i][j].end;
      int weight= G[i][j].weight;
      int t = dfs(G, next, target, ans);
      if (t)
        ans = min(ans, weight);
      reachable |= t;
    }
  }

  return reachable;
}

int main () {__
  int n, m;
  int TC = 0;
  while (cin >> n >> m) {
    if (n + m == 0) break;

    for (int i = 0; i < mx; ++i) visited[i] = 0;
    TC ++;
    int a, b, w;
    vector<edge> v;

    for (int i = 0; i < m; ++i) {
      cin >> a >> b >> w;
      edge e;
      e.weight = w;
      e.start  = a;
      e.end    = b;
      v.push_back(e);
    }

    int init, end, tot;
    cin >> init >> end >> tot;

    vector< vector<edge> > G = krustal(v, n);

    int cap = INT_MAX;
    dfs(G, init, end, cap);
    cap --;
    int ans = (tot + cap - 1) / cap;

    cout << "Scenario #" << TC << endl << "Minimum Number of Trips = " << max(1, ans) << endl << endl;
  }
}
