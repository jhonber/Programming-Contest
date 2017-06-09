// http://codeforces.com/contest/813/problem/C

#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

const int MAX = 222222;
vector<int> G[MAX];
vector<int> dist_root(MAX, 0);
vector<int> visited(MAX, 0);
int ans = 0;

void dfs (int i, int d, bool bob = false) {
  if (!visited[i]) {
    visited[i] = true;
    if (!bob)
      dist_root[i] = d;

    if (bob && dist_root[i] > d) {
      ans = max(ans, dist_root[i] * 2);
    }

    for (int j = 0; j < G[i].size(); ++j) {
      int next = G[i][j];
      dfs(next, d + 1, bob);
    }
  }
}

int main() {
  int n, x;
  cin >> n >> x;
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  dfs(1, 0);
  for (int i = 0; i < MAX; ++i) visited[i] = 0;

  dfs(x, 0, true);
  cout << ans << endl;

  return 0;
}