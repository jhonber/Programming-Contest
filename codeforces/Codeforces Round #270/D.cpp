// http://codeforces.com/contest/472/problem/D

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

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

const int mx = 100100;

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
void krustal (vector<edge> &e, int &n, vector< vector<edge> > &G) {
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
    }
  }
}


void dfs (int init, int i, int d, vector<int> &visited, vector< vector<edge> > &G, vector< vector<int> > &mat) {
  if (!visited[i]) {
    visited[i] = true;
    for (int j = 0; j < G[i].size(); ++j) {
      int cur = G[i][j].end;
      if (visited[cur]) continue;
      int cost = d + G[i][j].weight;
      mat[init][cur] = cost;
      dfs (init, cur, cost, visited, G, mat);
    }
  }
}

bool check (vector< vector<int> > &mat, int &n, vector< vector<edge> > &G) {
  vector< vector<int> > mat2 (n, vector<int> (n));

  vector<int> visited(n);
  for (int i = 0; i < n; ++i) {
    for (int x = 0; x < n; ++x) visited[x] = 0;
    dfs (i, i, 0, visited, G, mat2);
  }

  int zeros = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        if (!mat[i][j]) zeros ++;
        if (mat[i][j] != mat[j][i] || mat[i][j] != mat2[i][j])
          return false;
      }
    }

  n ++;
  if (zeros == (n * (n - 1)) / 2) return false;
  return true;
}

int main() {
  int n;
  scanf("%d", &n);

  vector< vector<int> > mat(n, vector<int> (n));
  vector<edge> v;

  edge e;
  int ind = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &mat[i][j]);
      if (i < j) {
        e.weight = mat[i][j];
        e.start  = i;
        e.end    = j;
        v.push_back(e);
      }
    }
  }

  vector< vector<edge> > G(n);
  krustal(v, n, G);

  if (n == 1 && !mat[0][0]) {
    cout << "YES";
    return 0;
  }

  if (!check(mat, n, G)) cout << "NO";
  else cout << "YES";

  return 0;
}