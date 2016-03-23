#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  int a, b;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    if (a % 2 == 0) a ++;
    int ans = 0;
    for (int j = a, x = 0; x < b; j += 2, ++x) ans += j;
    cout << ans << endl;
  }

  return 0;
}
