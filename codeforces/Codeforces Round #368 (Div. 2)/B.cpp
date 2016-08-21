// http://codeforces.com/contest/707/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() { IO
  long long n, m, k;
  cin >> n >> m >> k;

  set<int> paila;
  map<pair<int, int>, long long> cost;
  vector<int> G[n + 1];
  for (int i = 0; i < m; ++i) {
    long long a, b, c;
    cin >> a >> b >> c;
    G[a].push_back(b);
    G[b].push_back(a);

    if (a > b) swap(a, b);

    long long tmp = cost[{a, b}];
    if (tmp == 0)
      cost[{a, b}] = c;
    else
      cost[{a, b}] = min(tmp, c);
  }

  for (int i = 0; i < k; ++i) {
    int a;
    cin >> a;
    paila.insert(a);
  }

  long long ans = LLONG_MAX;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < G[i].size(); ++j) {
      int a = i;
      int b = G[i][j];
      if (paila.count(a) != paila.count(b)) {
        if (a > b) swap(a, b);
        ans = min(ans, cost[{a, b}]);
      }
    }
  }

  cout << (ans != LLONG_MAX ? ans : -1) << endl;
  return 0;
}