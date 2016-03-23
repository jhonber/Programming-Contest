#include<bits/stdc++.h>
using namespace std;

double d (double x1, double y1, double x2, double y2) {
  double a = x2 - x1;
  double b = y2 - y1;

  return sqrt(a*a + b*b);
}

int main() {
  double r1, x1, y1, r2, x2, y2;
  while (cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2) {
    double dist = d(x1, y1, x2, y2);
    if (r1 < r2 || dist + r2 > r1) cout << "MORTO" << endl;
    else cout << "RICO" << endl;
  }

  return 0;
}