#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int a;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    int ans = 0;
    if (a >= 2015) ans = (a - 2015) + 1;
    else ans = 2015 - a;
    if (a < 2015) cout << ans << " D.C." << endl;
    else cout << ans << " A.C." << endl;
  }
}