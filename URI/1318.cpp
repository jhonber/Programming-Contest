#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, m;
  while (cin >> n >> m) {
    if (!n) break;
    int ans = 0;

    map<int, int> mapa;
    for (int i = 0; i < m; ++i) {
      int a;
      cin >> a;
      if (mapa.count(a) == 0) {
        mapa[a] ++;
      }
      else if (mapa[a] == 1) {
        mapa[a] ++;
        ans ++;
      }
    }

    cout << ans << endl;
  }
  return 0;
}