#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;

    string a, b;
    map<string, string> mapa;
    for (int i = 0; i < n; ++i) {
      cin >> a >> b;
      mapa[a] = b;
    }

    int m;
    cin >> m;

    int ans = 0;
    for (int i = 0; i < m; ++i) {
      cin >> a >> b;

      string ori = mapa[a];
      int cnt = 0;
      for (int j = 0; j < b.size(); ++j) if (b[j] != ori[j]) cnt ++;

      if (cnt > 1) ans ++;
    }

    cout << ans << endl;
  }

  return 0;
}