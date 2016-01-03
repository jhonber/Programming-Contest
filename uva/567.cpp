#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for (__typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

vector<int> G[222];
vector<int> visited(222);
int solve (int a, int b) {
  queue<int> Q;
  Q.push(a);
  vector<int> cost(222, 0);

  visited[a] = true;
  cost[a] = 0;
  int ans = 0;

  while (!Q.empty()) {
    int v = Q.front(); Q.pop();

    for (int i = 0; i < G[v].size(); ++i) {
      if (!visited[G[v][i]]) {
        cost[G[v][i]] = cost[v] + 1;
        if (G[v][i] == b) return cost[v];
        visited[G[v][i]] = true;
        Q.push(G[v][i]);
      }
    }
  }
}

int main() {
  int cnt = 1;
  int TC = 1;
  int k;
  while (cin >> k) {

    for (int i = 0; i < k; ++i){
      int b;
      cin >> b;
      G[cnt].push_back(b);
      G[b].push_back(cnt);
    }


    if (cnt % 19 == 0) {
      int n;
      cin >> n;
      cout << "Test Set #" << TC << endl;
      for (int i = 0; i < n; ++i) {
        int init, end;
        cin >> init >> end;
        for (int x = 0; x < 222; ++x) visited[x] = 0;
        int ans = solve(init, end);
        cout << (init < 10 ? " " : "");
        cout << init << " to ";
        cout << (end < 10 ? " " : "");
        cout << end << ": " << ans + 1 << endl;
      }

      cout << endl;
      for (int i = 0; i < 222; ++i) G[i].clear();
      TC ++;
      cnt =0;
    }
    cnt ++;
  }

  return 0;
}
