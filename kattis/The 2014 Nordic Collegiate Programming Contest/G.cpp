// https://ncpc14.kattis.com/problems/outing

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

int dp[1111][1111][11];

void dfs (int i, vector< vector<int> > &G, vector<int> &visited, int &size) {
  if (!visited[i]) {
    size ++;
    visited[i] = true;
    for (int j = 0; j < G[i].size(); ++j) {
      int next = G[i][j];
      dfs (next, G, visited, size);
    }
  }
}

int go (int i, int k, bool taken, int sum, vector<int> &toTake) {
  if (dp[i][sum][taken] != -1) return dp[i][sum][taken];
  if (i >= toTake.size()) return sum;

  int a = 0, b = 0;
  if (sum + toTake[i] <= k)
    a = go (i + 1, k, true, sum + toTake[i], toTake);
  b = go (i + 1, k, taken, sum, toTake);

  return dp[i][sum][taken] = max(a, b);
}

/** Krustal implementation
 *  Complexity: O(E log V)
 **/

const int mx = 1111;

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
int krustal (vector<edge> &e, int &n, int &k, vector< vector<int> > &G, vector< vector<int> > &G2) {
  vector<int> visited  (n + 1, 0);
  vector<int> visited2 (n + 1, 0);
  vector< int > toTake;
  int rest = 0;

  sort(e.begin(), e.end());
  init_set(n);

  for (int i = 0 ; i < e.size(); ++i) {
    int u = e[i].start;
    int v = e[i].end;
    int w = e[i].weight;

    if (find_set(u) == find_set(v)) {
      if (!visited[u]) {
        int sizeCycle  = 0;
        int totalNodes = 0;
        dfs (u, G, visited, sizeCycle);
        dfs (u, G2, visited2, totalNodes);

        if (sizeCycle <= k) {
          toTake.push_back(sizeCycle);
          rest += totalNodes - sizeCycle;
        }
      }
    }

    join(u, v);
  }

  memset(dp, -1, sizeof dp);
  int ans = go (0, k, 0, 0, toTake);
  int free = k - ans;
  if (rest >= free) ans = k;
  else ans += rest;
  return ans;
}

int main () {
  int n, k, b;
  while (cin >> n >> k) {

    vector<edge> v(n);
    vector< vector<int> > G(n + 1), G2(n + 1);
    edge e;

    for (int i = 0; i < n; ++i) {
      cin >> b;

      e.start  = i + 1;
      e.end    = b;
      e.weight = 1;
      v[i] = e;

      G[i + 1].push_back(b);
      G2[b].push_back(i + 1);
    }

    int ans = krustal(v, n, k, G, G2);
    cout << ans << endl;
  }
}
