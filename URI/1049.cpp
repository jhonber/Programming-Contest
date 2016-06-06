#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string a, b, c;
  cin >> a >> b >> c;

  string key = a + "-" + b + "-" + c;

  map<string, string> mapa;
  mapa["vertebrado-ave-carnivoro"] = "aguia";
  mapa["vertebrado-ave-onivoro"] = "pomba";

  mapa["vertebrado-mamifero-onivoro"] = "homem";
  mapa["vertebrado-mamifero-herbivoro"] = "vaca";

  mapa["invertebrado-inseto-hematofago"] = "pulga";
  mapa["invertebrado-inseto-herbivoro"] = "lagarta";

  mapa["invertebrado-anelideo-hematofago"] = "sanguessuga";
  mapa["invertebrado-anelideo-onivoro"] = "minhoca";


  cout << mapa[key] << endl;
  return 0;
}
