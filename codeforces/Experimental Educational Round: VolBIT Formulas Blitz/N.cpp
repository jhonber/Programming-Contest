// http://codeforces.com/contest/630/problem/N

#include<bits/stdc++.h>
using namespace std;

int main() {
  double a, b, c;

  cin >> a >> b >> c;

  double x1 = (-b + sqrt((b * b) - (4.0 * a * c))) / (2.0 * a);
  double x2 = (-b - sqrt((b * b) - (4.0 * a * c))) / (2.0 * a);

  if (x1 < x2) swap (x1, x2);
  printf("%.6lf\n%.6lf", x1, x2);
  return 0;
}