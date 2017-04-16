// http://codeforces.com/contest/797/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    int sum_even_pos = 0;
    int sum_odd_pos = 0;
    int tot_odd = 0;
    int min_odd_neg = -INT_MAX;
    int min_odd_pos = INT_MAX;

    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;

      if (x > 0) {
        if (x % 2 == 0) sum_even_pos += x;
        else {
          sum_odd_pos += x;
          tot_odd ++;
          min_odd_pos = min(min_odd_pos, x);
        }
      }
      else {
        if (x % 2 != 0) {
          min_odd_neg = max(min_odd_neg, x);
        }
      }
    }

    int ans = sum_odd_pos + sum_even_pos;
    if (ans % 2 == 0) {
      ans -= min(abs(min_odd_neg), min_odd_pos);
    }

    cout << ans << endl;
  }

  return 0;
}