#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string pass;

  while (cin >> pass) {
    if (pass == "2002") {
      cout << "Acesso Permitido" << endl;
      break;
    }
    else cout << "Senha Invalida" << endl;
  }

  return 0;
}