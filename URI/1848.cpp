#include<bits/stdc++.h>
using namespace std;

int main() {

  map<string, int> mapa;
  mapa["---"] = 0;
  mapa["--*"] = 1;
  mapa["-*-"] = 2;
  mapa["-**"] = 3;
  mapa["*--"] = 4;
  mapa["*-*"] = 5;
  mapa["**-"] = 6;
  mapa["***"] = 7;

  int ans = 0;
  string s;
  while (cin >> s) {
    if (s == "caw") {
      cin >> s;
      cout << ans << endl;
      ans = 0;
    }
    else ans += mapa[s];
  }

}

