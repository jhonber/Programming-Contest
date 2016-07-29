// http://codeforces.com/contest/702/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  const long long INF = (1e9 * 1e5) + 100;

  map<long long, vector<int>> cnt;
  vector<long long> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    cnt[v[i]].push_back(i);
  }

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int cur = v[i];

    long long p = 1;
    while (p < INF) {
      long long r = p - v[i];
      if (r > 0) {
        int tot = lower_bound(cnt[r].begin(), cnt[r].end(), i) - cnt[r].begin();
        ans += tot;
      }

      p *= 2LL;
    }
  }

  cout << ans << endl;

  return 0;
}