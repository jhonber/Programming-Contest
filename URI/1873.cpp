#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

string to_lower (string s) {
  for (int i = 0; i < s.size(); ++i)
    s[i] = tolower(s[i]);

  return s;
}

int main() {
  int t;
  cin >> t;

  map<string, vector<string>> mapa;
  mapa["pedra"] = {"lagarto", "tesoura"};
  mapa["papel"] = {"pedra", "spock"};
  mapa["tesoura"] = {"papel", "lagarto"};
  mapa["lagarto"] = {"spock", "papel"};
  mapa["spock"] = {"tesoura", "pedra"};

  while (t --> 0) {
    string a, b;
    cin >> a >> b;

    a = to_lower(a);
    b = to_lower(b);

    if (a == b) {
      cout << "empate" << endl;
    }
    else {
      if (b == mapa[a][0] || b == mapa[a][1]) {
        cout << "rajesh" << endl;
      }
      else {
        cout << "sheldon" << endl;
      }
    }

  }

  return 0;
}