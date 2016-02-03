#include<bits/stdc++.h>
using namespace std;

int main() {
  int ans = 0;
  for (int i = 0; i < 6; ++i) {
    double a;
    cin >> a;

    if (a >= 0.0) ans ++;
  }

  cout << ans << " valores positivos" << endl;
  return 0;
}
