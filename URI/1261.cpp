#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, m;
  cin >> n >> m;

  string a;
  long long b;

  map<string, long long> mapa;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    mapa[a] = b;
  }

  string x;
  for (int i = 0; i < m; ++i) {
    long long ans = 0;
    while (true) {
      cin >> x;
      if (x == ".") break;
      else {
        if (mapa.count(x) != 0) {
          ans += mapa[x];
        }
      }
    }
    cout << ans << endl;
  }



  return 0;
}