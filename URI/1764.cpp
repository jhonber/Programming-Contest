#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

/** Krustal implementation
 *  Complexity: O(E log V)
 **/

const int mx = 50005;

struct edge {
  int start, end, weight;
  edge(){} edge(int start, int end, int weight) : start(start), end(end), weight(weight) {}
  bool operator < (const edge &that) const {
    // Change < by > to find maximum spanning tree
    return weight < that.weight;
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
long long krustal (vector<edge> &e, int &n) {
  double tot = 0;
  sort(e.begin(), e.end());
  init_set(n);

  for (int i = 0 ; i < e.size(); ++i) {
    int u = e[i].start;
    int v = e[i].end;
    int w = e[i].weight;
    if (find_set(u) != find_set(v)) {
      join(u, v);
      tot += w;
    }
  }
   return tot;
}

int main() {

  int n,m;
  while (cin >> n >> m) {
    if (!n) break;

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

    long long ans = krustal(v, n);
    cout << ans << endl;

  }
  return 0;
}
