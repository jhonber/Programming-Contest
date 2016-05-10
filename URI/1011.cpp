#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  double r;
  cin >> r;

  double area = (4 / 3.0) * (3.14159) * (r * r * r);
  printf("VOLUME = %.3lf\n", area);

  return 0;
}