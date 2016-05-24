#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;
#define PI acos(-1)

int main() {
  double a, b, c;

  while (cin >> a >> b >> c) {
    double ang = (a / 180.0) * PI;
    double ans = (tan(ang) * b) + c;
    printf("%.2lf\n", ans * 5);
  }
  return 0;
}