#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " " << (x) << endl;

int main() {
  int n;
  cin >> n;

  string a, b;
  while (n --> 0) {
    cin >> a >> b;

    int ans = 0;
    for (int i = 0; i < a.size(); ++i) {
      int x1 = a[i] - 'a';
      int x2 = b[i] - 'a';

      int diff = x2 - x1;
      if (diff >= 0) ans += diff;
      else {
        ans += 'z' - a[i];
        ans += (b[i] - 'a') + 1;
      }

    }
    cout << ans << endl;;
  }

  return 0;
}