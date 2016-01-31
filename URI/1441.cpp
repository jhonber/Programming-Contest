#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;

    if (n == 1) {
      cout << 1 << endl;
      continue;
    }

    long long ans = n;
    long long cur = -1, bef = n;
    while (cur != 1) {
      if (bef % 2 != 0) {
        cur = bef * 3 + 1;
      }
      else {
        cur = bef / 2;
      }

      if (cur > ans) ans = cur;
      bef = cur;
    }

    cout << ans << endl;
  }

  return 0;
}