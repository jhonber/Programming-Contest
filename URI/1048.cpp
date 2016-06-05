#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " < (x) << endl;

int main() {
  double x;
  cin >> x;

  double v[] = {.15, .12, .10, .07, .04};

  if (x <= 400) {
    double a = x + (v[0] * x);
    printf("Novo salario: %.2lf\n", a);
    printf("Reajuste ganho: %.2lf\n", a - x);
    printf("Em percentual: %d %\n", 15);
  }
  else if (x > 400 && x <= 800) {
    double a = x + (v[1] * x);
    printf("Novo salario: %.2lf\n", a);
    printf("Reajuste ganho: %.2lf\n", a - x);
    printf("Em percentual: %d %\n", 12);
  }
  else if (x > 800 && x <= 1200) {
    double a = x + (v[2] * x);
    printf("Novo salario: %.2lf\n", a);
    printf("Reajuste ganho: %.2lf\n", a - x);
    printf("Em percentual: %d %\n", 10);

  }
  else if (x > 1200 && x <= 2000) {
    double a = x + (v[3] * x);
    printf("Novo salario: %.2lf\n", a);
    printf("Reajuste ganho: %.2lf\n", a - x);
    printf("Em percentual: %d %\n", 7);
  }
  else {
    double a = x + (v[4] * x);
    printf("Novo salario: %.2lf\n", a);
    printf("Reajuste ganho: %.2lf\n", a - x);
    printf("Em percentual: %d %\n", 4);
  }

  return 0;
}