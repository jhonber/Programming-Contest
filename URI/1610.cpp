#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t;
  cin >> t;

  while (t --> 0) {
    int n, m;
    cin >> n >> m;

    vector<int> G[n + 1];
    vector<int> inc(n + 1, 0);

    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b; a --; b --;
      G[b].push_back(a);
      inc[a] ++;
    }

    int paila = false;
    queue<int> Q;
    for (int i = 0; i < n; ++i) {
      if (inc[i] == 0) {
        Q.push(i);
      }
    }

    int cnt = 0;
    while (!Q.empty()) {
      int cur = Q.front(); Q.pop();
      cnt ++;

      for (int i = 0; i < G[cur].size(); ++i) {
        inc[G[cur][i]] --;
        if (inc[G[cur][i]] == 0) {
          Q.push(G[cur][i]);
        }
      }
    }

    if (cnt != n) paila = true;
    cout << (paila ? "SIM" : "NAO") << endl;
  }

  return 0;
}