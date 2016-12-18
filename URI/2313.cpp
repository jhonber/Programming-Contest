#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main () {
  int v[3];
  cin >> v[0] >> v[1] >> v[2];

  sort(v, v + 3);

  if (v[0] + v[1] > v[2]) {
    bool eq = false;
    if (v[0] * v[0] + v[1] * v[1] == v[2] * v[2]) eq = true;

    if (v[0] == v[1] && v[1] == v[2]) cout << "Valido-Equilatero";
    else if (v[0] == v[1] || v[1] == v[2]) cout << "Valido-Isoceles";
    else cout << "Valido-Escaleno";

    cout << endl << "Retangulo: " << (eq ? "S" : "N" ) << endl;
  }
  else {
    cout << "Invalido" << endl;
  }

  return 0;
}