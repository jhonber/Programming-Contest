#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  double a, b, c;
  a = (1 + sqrt(5)) / 2;
  b = (1 - sqrt(5)) / 2;
  c = sqrt(5);

  double fib = (pow(a, n) - pow(b, n)) / c;
  cout << fixed << setprecision(1) << fib << endl;
  return 0;
}