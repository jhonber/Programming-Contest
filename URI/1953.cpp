#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

int main() {
  int n;
  while (cin >> n) {
    long long a;
    string code;
    map<string, int> mapa;
    for (int i = 0; i < n; ++i) {
      cin >> a >> code;
      mapa[code] ++;
    }

    int others = n - (mapa["EPR"] + mapa["EHD"]);
    cout << "EPR: " << mapa["EPR"] << endl;
    cout << "EHD: " << mapa["EHD"] << endl;
    cout << "INTRUSOS: " << others << endl;
  }

  return 0;
}