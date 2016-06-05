#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " < (x) << endl;

int main() {
  double a, b;
  cin >> a >> b;

  double ans = ((a * 3.5) + (b * 7.5)) / 11.0;
  printf("MEDIA = %.5lf\n", ans);

  return 0;
}