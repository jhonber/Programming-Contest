#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t;
  cin >> t;

  map<string, int> mapa;
  mapa["BG"] = 1;
  mapa["BR"] = 2;
  mapa["RB"] = 1;
  mapa["RG"] = 2;
  mapa["GR"] = 1;
  mapa["GB"] = 2;

  while (t --> 0) {
    int n;
    cin >> n;
    int a, b, c;
    a = b = c = 0;

    for (int i = 0; i < n; ++i) {
      string s1, s2;
      cin >> s1 >> s2;

      if (s1 == "R") {
        a += mapa[s1 + s2];
      }
      else if (s1 == "G") {
        b += mapa[s1 + s2];
      }
      else {
        c += mapa[s1 + s2];
      }
    }

    if (a == b && b == c) cout << "trempate" << endl;
    else {
      vector<pair<int, int>> v = {{a, 0}, {b, 1}, {c, 2}};
      sort(v.begin(), v.end());

      if (v[2].first == v[1].first) {
        cout << "empate" << endl;
      }
      else {
        vector<string> win = {"red", "green", "blue"};
        cout << win[v[2].second] << endl;
      }
    }
  }

  return 0;
}