#include<bits/stdc++.h>
using namespace std;



int main() {
  double v[3];
  double a, b, c;
  cin >> v[0] >> v[1] >> v[2];

  sort(v, v + 3);

  a = v[2];
  b = v[0];
  c = v[1];

  if (a >= b + c) {
    cout << "NAO FORMA TRIANGULO" << endl;
    return 0;
  }

  if (a * a == b * b + c * c) cout << "TRIANGULO RETANGULO" << endl;
  if (a * a > b * b + c * c) cout << "TRIANGULO OBTUSANGULO" << endl;
  if (a * a < b * b + c * c) cout << "TRIANGULO ACUTANGULO" << endl;
  if (a == b && b == c) cout << "TRIANGULO EQUILATERO" << endl;
  if (a == b && a != c || a == c && b != a || b == c && b != a ) cout << "TRIANGULO ISOSCELES" << endl;

  return 0;
}
