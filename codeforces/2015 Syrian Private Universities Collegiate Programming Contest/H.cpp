#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int n, m, k;
unsigned long long G[111][111];

void floyd (int n) {
  for (int k = 0; k < n; ++k){
    for (int i = 0; i < n; ++i){
      for (int j = 0; j < n; ++j){
        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
      }
    }
  }
}

int main() {
  int t;
  cin >> t;

  for (int x = 0; x < t; ++x) {
    cin >> n >> m >> k;

    for (int i = 0; i < 111; ++i)
      for (int j = 0; j < 111; ++j)
        if (i == j) G[i][j] = 0;
        else G[i][j] = INT_MAX;

    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      G[a][b] = G[b][a] =  c;
    }

    vector<int> v(k);
    for (int i = 0; i < k; ++i) cin >> v[i];

    sort(v.begin(), v.end());
    floyd(111);

    int ans = INT_MAX;
    do {
      int from, to;
      from = 1;
      int cost = 0;
      for (int i = 0; i < k; ++i) {
        to = v[i];
        cost += G[from][to];
        from = to;
      }

      cost += G[to][n];
      ans = min(cost, ans);
    }
    while (next_permutation(v.begin(), v.end()));

    cout << "Case " << x + 1 << ": " << ans << endl;
  }

  return 0;
}
