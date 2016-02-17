#include<bits/stdc++.h>
using namespace std;

map<int, string> mapa;

string f (int x) {
  auto up = mapa.upper_bound(x);
  up --;
  int key = up -> first;

  if (key == x) return mapa[x];
  return mapa[key] + f(x - key);
}

int main() {

  mapa[1] = "I";
  mapa[4] = "IV";
  mapa[5] = "V";
  mapa[9] = "IX";
  mapa[10] = "X";
  mapa[40] = "XL";
  mapa[50] = "L";
  mapa[90] = "XC";
  mapa[100] = "C";
  mapa[400] = "CD";
  mapa[500] = "D";
  mapa[900] = "CM";
  mapa[1000] = "M";

  int n;
  cin >> n;
  cout << f(n) << endl;

  return 0;
}
