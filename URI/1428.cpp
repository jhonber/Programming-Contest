#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t;
  cin >> t;

  while (t --> 0) {
    long double a, b;
    cin >> a >> b;

    long long ans = ceil((a - 2) / 3.0) * ceil((b - 2) / 3.0);
    cout << ans << endl;
  }
  return 0;
}
