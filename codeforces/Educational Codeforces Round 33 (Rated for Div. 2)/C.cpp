// http://codeforces.com/contest/893/problem/C
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) <<  endl;

const int MX = 1e5 + 100;
vector<int> G[MX];
vector<long long> v(MX);
vector<int> visited(MX, 0);
long long mm;

void dfs (int cur) {
  if (!visited[cur]) {
    mm = min(v[cur], mm);
    visited[cur] = true;
    for (int i = 0; i < G[cur].size(); ++i) {
      int next = G[cur][i];
      mm = min(mm, v[next]);
      dfs(next);
    }

  }
}

int main() {
#ifdef ONLINEJUDGE
  ios_base::sync_with_stdio(0); cin.tie(0);
#endif

  int n, m;
  while (cin >> n >> m) {
    for (int i = 1; i <= n; ++i) cin >> v[i];

    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      G[a].push_back(b);
      G[b].push_back(a);
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (!visited[i]) {
        mm = INT_MAX;
        dfs(i);
        ans += mm;
      }
    }

    cout << ans << endl;
  }

  return 0;
}
