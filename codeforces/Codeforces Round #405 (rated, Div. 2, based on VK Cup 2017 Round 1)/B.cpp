// http://codeforces.com/contest/791/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

long long sum (long long n) {
  return (n * (n + 1)) / 2;
}

bool f (int i, vector<vector<int>> &G, vector<int> &visited, long long &size, long long &cnt) {
  if (!visited[i]) {
    visited[i] = true;
    size ++;

    for (int j = 0; j < G[i].size(); ++j) {
      cnt ++;
      f (G[i][j], G, visited, size, cnt);
    }
  }
}

int main() {
  long long n, m;
  cin >> n >> m;

  const int MN = 222222;
  vector<vector<int>> G(MN);
  vector<int> visited(MN, 0);

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;

    G[a].push_back(b);
    G[b].push_back(a);
  }

  for (int i = 1; i <= n; ++i) {
    if (visited[i]) continue;
    long long size = 0;
    long long cnt = 0;
    f (i, G, visited, size, cnt);

    if (sum(size - 1) != cnt / 2) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
  return 0;
}