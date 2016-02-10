#include<bits/stdc++.h>
using namespace std;

int main() {
  double a, b, c;
  cin >> a >> b >> c;

  double v[] = {a, b, c};
  sort(v, v + 3);
  a = v[2];
  b = v[1];
  c = v[0];

  if (c + b > a) printf("Perimetro = %.1lf\n", a + b + c);
  else printf("Area = %.1lf\n", 0.5 * (a + b) * c);

  return 0;
}
