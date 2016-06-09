#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string line, nn;
  int n;
  while (true) {
    getline(cin, nn);
    if (nn == "0") break;
    n = atoi(nn.c_str());

    getline(cin, line);

    int i = 0, j = 0;
    map<char, int> mapa;

    int ans = 0;
    while (i < line.size() && j < line.size()) {
      char c = line[j];
      mapa[c] ++;

      if (mapa.size() > n) {
        ans = max(ans, (j - i));
        while (i < line.size() && mapa.size() > n) {
          int cc = line[i];
          mapa[cc] --;
          if (mapa[cc] == 0) {
            mapa.erase(cc);
          }

          i ++;
        }
      }

      j ++;
    }

    ans = max(ans, j - i);

    cout << ans << endl;

  }
  return 0;
}