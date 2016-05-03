#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  map<int, string> mapa;
  mapa[1] = "Rolien";
  mapa[2] = "Naej";
  mapa[3] = "Elehcim";
  mapa[4] = "Odranoel";

  while (n --> 0) {
    int k, a;
    cin >> k;

    for (int i = 0; i < k; ++i) {
      cin >> a;
      cout << mapa[a] << endl;
    }

  }

  return 0;
}