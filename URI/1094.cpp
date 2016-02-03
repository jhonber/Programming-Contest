#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int a;
  char c;
  int tot = 0;
  map<char, int> mapa;
  for (int i = 0; i < n; ++i) {
    cin >> a >> c;
    mapa[c] += a;
    tot += a;
  }

  cout << "Total: " << tot << " cobaias" << endl;
  cout << "Total de coelhos: " << mapa['C'] << endl;
  cout << "Total de ratos: " << mapa['R'] << endl;
  cout << "Total de sapos: " << mapa['S'] << endl;
  printf("Percentual de coelhos: %.2lf %\n", (mapa['C'] * 100.0) / tot);
  printf("Percentual de ratos: %.2lf %\n", (mapa['R'] * 100.0) / tot);
  printf("Percentual de sapos: %.2lf %\n", (mapa['S'] * 100.0) / tot);
  return 0;
}