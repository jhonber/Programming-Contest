// http://codeforces.com/contest/231/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int b_search (vector<long long> &pre, vector<int> &v, int &pos, int &k) {
  int lo = 1;
  int hi = pos;
  int mid, tot = 0;

  while (lo < hi) {
    mid = (lo + hi) / 2;

    long long need = (pos - mid + 0LL) * v[pos];
    long long sum = pre[pos - 1] - pre[mid - 1];
    long long r = need - sum;

    if (r <= k) {
      hi = mid;
      tot = pos - mid + 1;
    }
    else {
      lo = mid + 1;
    }
  }

  return max(tot, 1);
}

int main() {
  int n, k;
  int TC = 1;
  while (cin >> n >> k) {

    vector<int> v(n + 1, 0);
    for (int i = 0; i < n; ++i) cin >> v[i + 1];

    sort(v.begin() + 1, v.end());

    vector<long long> pre(n + 10);
    pre[0] = 0;
    for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + v[i];

    int ans = INT_MAX;
    int best = 0;
    for (int i = n; i >= 1; --i) {
      int cur = b_search(pre, v, i, k);
      if (cur >= best) {
        best = cur;
        ans = v[i];
      }
    }

    cout << best << " " << ans << endl;
  }

  return 0;
}