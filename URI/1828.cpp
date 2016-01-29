#include<bits/stdc++.h>
using namespace std;

int main() {
  map< pair<string, string>, string> mapa;

  mapa[{"tesoura", "papel"}] = "Bazinga!";
  mapa[{"papel", "pedra"}] = "Bazinga!";
  mapa[{"pedra", "lagarto"}] = "Bazinga!";
  mapa[{"lagarto", "Spock"}] = "Bazinga!";
  mapa[{"Spock", "tesoura"}] = "Bazinga!";
  mapa[{"tesoura", "lagarto"}] = "Bazinga!";
  mapa[{"lagarto", "papel"}] = "Bazinga!";
  mapa[{"papel", "Spock"}] = "Bazinga!";
  mapa[{"Spock", "pedra"}] = "Bazinga!";
  mapa[{"pedra", "tesoura"}] = "Bazinga!";

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    string a, b;
    cin >> a >> b;

    cout << "Caso #" << i + 1 << ": ";
    if (a == b) cout << "De novo!";
    else if (mapa[{a,b}] == "Bazinga!") cout << mapa[{a,b}];
    else cout << "Raj trapaceou!";
    cout << endl;
  }

  return 0;
}