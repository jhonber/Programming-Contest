#include<bits/stdc++.h>
using namespace std;

int main() {
  double a,b,c;
  cin >> a >> b >> c;

  double ans = b * c;
  cin >> a >> b >> c;

  ans += b * c;

  printf("VALOR A PAGAR: R$ %.2lf\n", ans);
  return 0;
}