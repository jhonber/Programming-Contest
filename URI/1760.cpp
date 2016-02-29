#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  double s;

  while (cin >> s) {
    double ans = (s * s * 2.0 * sqrt(3.0)) / 5.0;
    printf("%.2lf\n", ans);
  }

  return 0;
}
