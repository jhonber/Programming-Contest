#include<bits/stdc++.h>
using namespace std;

#define d(x) cout << #x << " = " < (x) << endl;

int main() {
  int n, m;
  cin >> n >> m;


  map<int, double> mapa;
  mapa[1] = 4;
  mapa[2] = 4.5;
  mapa[3] = 5;
  mapa[4] = 2;
  mapa[5] = 1.5;

  cout << fixed << setprecision(2);
  cout << "Total: R$ " << mapa[n] * m << endl;
  return 0;
}