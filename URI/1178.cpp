#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  double a;
  cin >> a;

  for (int i = 0; i < 100; ++i) {
    printf("N[%d] = %.4lf\n", i, a);
    a /= 2;
  }

  return 0;
}