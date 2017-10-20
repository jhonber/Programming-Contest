// http://codeforces.com/contest/863/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    n *= 2;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;

        vector<int> t = v;
        t[i] = t[j] = 0;
        sort(t.begin(), t.end());
        t.erase(t.begin());
        t.erase(t.begin());

        int tot = 0;
        for (int k = 1; k < t.size(); k += 2) {
          tot += t[k] - t[k - 1];
        }

        ans = min(ans, tot);
      }
    }

    cout << ans << endl;
  }

  return 0;
}