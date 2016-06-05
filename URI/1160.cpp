#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t;
  cin >> t;

  double a, b, c, d;
  while (t --> 0) {
    cin >> a >> b >> c >> d;

    c /= 100;
    d /= 100;

    int years = 0;
    int cnt = 100;
    while (cnt --> 0 && a <= b) {
      a = a + (int)(a * c);
      b = b + (int)(b * d);
      years ++;
    }

    if (a >= b) cout << years << " anos." << endl;
    else cout << "Mais de 1 seculo." << endl;
  }

  return 0;
}