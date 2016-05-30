#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, m;
  while (cin >> n >> m) {
    if (n + m == 0) break;

    map<int, int> mapa;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;

      mapa[a] ++;
    }

    int ans = 0;
    for (auto i: mapa) {
      if (i.second >= m) ans ++;
    }

    cout << ans << endl;
  }

  return 0;
}