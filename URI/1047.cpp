#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int h1, m1, h2, m2;
  cin >> h1 >> m1 >> h2 >> m2;

  int mins = 0;
  int f = false;
  while (!f) {
    while (m1 < 60) {
      if (h1 == h2 && m1 == m2) {
        f = true;
        break;
      }
      m1 ++;
      mins ++;
    }

    h1 ++;
    m1 = 0;
    if (h1 == 24) h1 = 0;
  }

  if (mins == 0) mins = 60 * 24;
  cout << "O JOGO DUROU " << mins / 60 << " HORA(S) E " << mins % 60 << " MINUTO(S)" << endl;
  return 0;
}