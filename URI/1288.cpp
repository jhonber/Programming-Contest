#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int dp[55][555][5];

int go (int i, bool taken, int w, int &k, vector< pair<int, int> > &v) {
  if (dp[i][w][taken] != -1) return dp[i][w][taken];
  if (i == v.size()) return 0;

  int a = 0;
  int b = 0;

  if (w + v[i].second <= k)
    a += go(i + 1, true, w + v[i].second, k, v) + v[i].first;
  b += go(i + 1, taken, w, k, v);

  return dp[i][w][taken] = max(a, b);
}

int main() { IO
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;

    vector< pair<int, int> > v(n);
    for (int j = 0; j < n; ++j) {
      int x, y;
      cin >> x >> y;
      v[j] = {x, y};
    }

    int k,r;
    cin >> k >> r;

    memset(dp, -1, sizeof dp);
    int tot = go (0, 0, 0, k, v);

    if (tot >= r)
      cout << "Missao completada com sucesso" << endl;
    else
      cout << "Falha na missao" << endl;
  }

  return 0;
}
