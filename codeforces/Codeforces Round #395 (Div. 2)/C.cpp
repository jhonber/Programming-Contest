// http://codeforces.com/contest/764/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

vector<int> G[110000];
vector<int> color(110000, 0);
vector<int> visited(110000, 0);

bool check (int i, int root) {
  queue<int> Q;
  Q.push(i);

  while (!Q.empty()) {
    int cur = Q.front(); Q.pop();
    visited[cur] = true;

    for (int j = 0; j < G[cur].size(); ++j) {
      int next = G[cur][j];
      if (next == root) continue;
      if (color[next] != color[cur]) return false;
      if (!visited[next]) {
        Q.push(next);
      }
    }
  }

  return true;
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;

    G[a].push_back(b);
    G[b].push_back(a);
  }

  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    color[i + 1] = a;
  }

  int mm = 0;
  int bestRoot = -1;

  for (int i = 1; i <= n; ++i) {
    int cnt = 0;
    for (int j = 0; j < G[i].size(); ++j) {
      int child = G[i][j];
      if (color[child] != color[i]) {
        cnt ++;
      }
    }

    if (cnt > mm) {
      mm = cnt;
      bestRoot = i;
    }
  }

  if (bestRoot == -1) {
    cout << "YES" << endl;
    cout << 1 << endl;
    return 0;
  }

  bool ok = true;
  for (int j = 0; j < G[bestRoot].size(); ++j) {
    int child = G[bestRoot][j];
    if (!check(child, bestRoot)) {
      ok = false;
      break;
    }
  }

  if (ok) {
    cout << "YES" << endl;
    cout << bestRoot << endl;
  }
  else cout << "NO" << endl;

  return 0;
}