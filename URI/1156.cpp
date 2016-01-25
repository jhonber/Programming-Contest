#include<bits/stdc++.h>
using namespace std;

int main() {
  double ans = 1;
  for (int i = 3, j = 0; i <= 39; i += 2, ++j) {
    ans += (double)i / (2<<j);
  }

  printf("%.2lf\n", ans);
  return 0;
}