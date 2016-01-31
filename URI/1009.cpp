#include<bits/stdc++.h>
using namespace std;

int main() {
  string s;
  double a, b;
  cin >> s >> a >> b;

  double tot = a + ((b * 15.0) / 100.0);
  printf("TOTAL = R$ %.2lf\n", tot);
  return 0;
}
