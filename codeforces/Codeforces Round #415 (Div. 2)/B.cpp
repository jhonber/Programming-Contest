// http://codeforces.com/contest/810/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
  int n, f;
  while (cin >> n >> f) {
    vector<pair<long long, int>> best;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i];
      int a = min(2 * x[i], y[i]);
      int b = min(x[i], y[i]);
      int x = a - b;
      best.push_back({x, i});
    }

    sort(best.begin(), best.end());

    map<int, long long> cnt;
    for (int i = 0, j = n - 1; i < f; ++i, --j) {
      int k = best[j].second;
      cnt[best[j].second] = min(2 * x[k], y[k]);
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      if (cnt.count(i) > 0) {
        ans += cnt[i];
      }
      else {
        ans += min(x[i], y[i]);
      }
    }

    cout << ans << endl;
  }

  return 0;
}