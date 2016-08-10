#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    int bef;
    cin >> bef;

    int ans = 0;
    int f = true;
    for (int i = 1; i < n; ++i) {
      int x;
      cin >> x;
      if (bef > x && f) {
        ans = i + 1;
        f = false;
      }

      bef = x;
    }

    cout << ans << endl;
  }

  return 0;
}