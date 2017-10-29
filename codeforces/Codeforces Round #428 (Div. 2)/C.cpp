// http://codeforces.com/contest/839/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MX = 100100;
vector<int> G[MX];
vector<int> visited(MX, 0);

double f (int i) {
  visited[i] = true;
  if (G[i].size() == 1 && i != 1) {
    return 0;
  }

  double exp = 0;
  double n = G[i].size() - (i == 1 ? 0: 1);
  for (int j = 0; j < G[i].size(); ++j) {
    int next = G[i][j];
    if (next == i || visited[next]) continue;
    exp += (1.0 / n) * (f(next) + 1);
  }

  return exp;
}

int main() {
  int n;
  while (cin >> n) {
    for (int i = 1; i < n; ++i) {
      int a, b;
      cin >> a >> b;
      G[a].push_back(b);
      G[b].push_back(a);
    }

    double ans = f(1);
    cout << fixed << setprecision(10) << ans << endl;
  }

  return 0;
}