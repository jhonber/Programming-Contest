// http://codeforces.com/contest/892/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
//  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n;
  while (cin >> n) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    int ones = 0;
    for (int i = 0; i < n; ++i) {
      ones += (v[i] == 1);
    }

    if (ones) {
      cout << n - ones << endl;
      continue;
    }
    else {
      int ans = 1e9;
      for (int i = 0; i < n; ++i) {
        int k = 0;
        for (int j = i; j < n; ++j) {
          k = __gcd(k, v[j]);
          if (k == 1) {
            int cur = (j - i) + (n - 1);
            ans = min(ans, cur);
          }
        }
      }

      cout << (ans == 1e9 ? -1 : ans) << endl;
    }
  }

  return 0;
}