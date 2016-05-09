#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  map<char, int> mapa;
  mapa['0'] = 6;
  mapa['1'] = 2;
  mapa['2'] = 5;
  mapa['3'] = 5;
  mapa['4'] = 4;
  mapa['5'] = 5;
  mapa['6'] = 6;
  mapa['7'] = 3;
  mapa['8'] = 7;
  mapa['9'] = 6;

  while (n --> 0) {
    string num;
    cin >> num;

    int ans = 0;
    for (int i = 0; i < num.size(); ++i) {
      ans += mapa[num[i]];
    }

    cout << ans << " leds" << endl;
  }

  return 0;
}