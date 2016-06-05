#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " < (x) << endl;

int main() {
  map<int, string> mapa;

  mapa[61] = "Brasilia";
  mapa[71] = "Salvador";
  mapa[11] = "Sao Paulo";
  mapa[21] = "Rio de Janeiro";
  mapa[32] = "Juiz de Fora";
  mapa[19] = "Campinas";
  mapa[27] = "Vitoria";
  mapa[31] = "Belo Horizonte";

  int n;
  cin >> n;

  if (mapa.count(n) == 0) cout << "DDD nao cadastrado" << endl;
  else cout << mapa[n] << endl;
  return 0;
}