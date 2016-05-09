#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

void f (double a, double b, double c) {
  double d = (b * b) - (4 * a * c);

  if (a == 0.0 || d < 0) {
    cout << "Impossivel calcular" << endl;
    return;
  }

  double R1 = (-b + sqrt(d) ) / (2 * a);
  double R2 = (-b - sqrt(d) ) / (2 * a);

  printf("R1 = %.5lf\n", R1);
  printf("R2 = %.5lf\n", R2);
}

int main() {
  double a, b, c;
  cin >> a >> b >> c;

  f(a, b, c);
  return 0;
}