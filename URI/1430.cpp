#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {

  map<char, double> mapa;
  mapa['W'] = 1;
  mapa['H'] = 1/2.0;
  mapa['Q'] = 1/4.0;
  mapa['E'] = 1/8.0;
  mapa['S'] = 1/16.0;
  mapa['T'] = 1/32.0;
  mapa['X'] = 1/64.0;

  string s;
  while (getline(cin, s)) {
    if (s == "*") break;

    int ans = 0;
    double cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '/') {
        ans += (cnt == 1 ? 1 : 0);
        cnt = 0;
        continue;
      }

      cnt += mapa[s[i]];
    }

    cout << ans << endl;
  }

  return 0;
}