#include<bits/stdc++.h>
using namespace std;

int main() {
  string a, b;

  while (cin >> a >> b) {
    if (a == "0" && b == "0") break;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int lim = min((int)a.size(), (int)b.size());
    int carry = 0;
    int ans = 0;

    for (int i = 0; i < lim; ++i) {
      int cur = (a[i] - '0') + (b[i] - '0') + carry;
      carry = cur / 10;
      if (carry) ans ++;
    }

    if (a.size() > b.size()) {
      if (lim < a.size()) {
        int cur = (a[lim] - '0') + carry;
        carry = cur / 10;
        if (carry) ans ++;
      }
    }
    else {
      if (lim < b.size()) {
        int cur = (b[lim] - '0') + carry;
        carry = cur / 10;
        if (carry) ans ++;
      }
    }

    if (!ans) cout << "No carry operation." << endl;
    else if (ans == 1) cout << "1 carry operation." << endl;
    else cout << ans << " carry operations." << endl;
  }

  return 0;
}