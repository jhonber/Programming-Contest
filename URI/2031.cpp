#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  map<pair<string, string>, string> mapa;
  mapa[{"ataque", "pedra"}] = "Jogador 1 venceu";
  mapa[{"ataque", "papel"}] = "Jogador 1 venceu";
  mapa[{"pedra", "papel"}] = "Jogador 1 venceu";
  mapa[{"papel", "papel"}] = "Ambos venceram";
  mapa[{"pedra", "pedra"}] = "Sem ganhador";
  mapa[{"ataque", "ataque"}] = "Aniquilacao mutua";

  int n;
  cin >> n;

  while (n --> 0) {
    string a, b;
    cin >> a >> b;

    if (mapa.count({a, b}) > 0) {
      cout << mapa[{a,b}] << endl;
    }
    else cout << "Jogador 2 venceu" << endl;
  }

  return 0;
}