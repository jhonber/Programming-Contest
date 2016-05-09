#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  double a, b, c;
  cin >> a >> b >> c;

  double x1, x2, x3, x4, x5;
  x1 = (a * c) / 2;
  x2 = (3.14159) * c * c;
  x3 = ((a + b) / 2.0) * c;
  x4 = b * b;
  x5 = a * b;

  printf("TRIANGULO: %.3lf\n", x1);
  printf("CIRCULO: %.3lf\n", x2);
  printf("TRAPEZIO: %.3lf\n", x3);
  printf("QUADRADO: %.3lf\n", x4);
  printf("RETANGULO: %.3lf\n", x5);

  return 0;
}