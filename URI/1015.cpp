#include<bits/stdc++.h>
using namespace std;

int main() {
  double a, b, c, d;
  cin >> a >> b >> c >> d;

  double dist = sqrt( ((a - c) * (a - c)) + ((b - d) * (b - d)) );
  printf("%.4lf\n", dist);

  return 0;
}