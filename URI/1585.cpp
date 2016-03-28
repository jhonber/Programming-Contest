#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  while (n --> 0) {
    double a, b;
    cin >> a >> b;

    int ans = (a * b) / 2.;
    cout << ans << " cm2" << endl;
  }

  return 0;
}
