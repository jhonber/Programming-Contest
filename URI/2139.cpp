#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int a, b;
  int ans = 366 - 7;
  int days[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  map<int, string> mapa;
  mapa[0] = "E vespera de natal!";
  mapa[1] = "E natal!";
  mapa[2] = "Ja passou!";

  while (cin >> a >> b) {
    if (a == 12 && b == 24) cout << mapa[0];
    else if (a == 12 && b == 25) cout << mapa[1];
    else if (a == 12 && b > 25) cout << mapa[2];
    else {
      int sum = 0;
      for (int i = 0; i < a - 1; ++i) sum += days[i];

      cout << "Faltam " << ans - (b + sum) + 1 << " dias para o natal!";
    }
    cout << endl;
  }

  return 0;
}