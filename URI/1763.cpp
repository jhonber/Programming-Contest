#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  map<string, string> mapa;
  mapa["brasil"]="Feliz Natal!";
  mapa["alemanha"]="Frohliche Weihnachten!";
  mapa["austria"]="Frohe Weihnacht!";
  mapa["coreia"]="Chuk Sung Tan!";
  mapa["espanha"]="Feliz Navidad!";
  mapa["grecia"]="Kala Christougena!";
  mapa["estados-unidos"]="Merry Christmas!";
  mapa["inglaterra"]="Merry Christmas!";
  mapa["australia"]="Merry Christmas!";
  mapa["portugal"]="Feliz Natal!";
  mapa["suecia"]="God Jul!";
  mapa["turquia"]="Mutlu Noeller";
  mapa["argentina"]="Feliz Navidad!";
  mapa["chile"]="Feliz Navidad!";
  mapa["mexico"]="Feliz Navidad!";
  mapa["antardida"]="Merry Christmas!";
  mapa["canada"]="Merry Christmas!";
  mapa["irlanda"]="Nollaig Shona Dhuit!";
  mapa["belgica"]="Zalig Kerstfeest!";
  mapa["italia"]="Buon Natale!";
  mapa["libia"]="Buon Natale!";
  mapa["siria"]="Milad Mubarak!";
  mapa["marrocos"]="Milad Mubarak!";
  mapa["japao"]="Merii Kurisumasu!";

  string a;
  while (cin >> a) {
    if (mapa.count(a) == 0) cout << "--- NOT FOUND ---" << endl;
    else cout << mapa[a] << endl;
  }
  return 0;
}
