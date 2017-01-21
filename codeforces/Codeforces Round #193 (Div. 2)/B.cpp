// http://codeforces.com/contest/332/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, k;
  cin >> n >> k;

  vector<long long> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  vector<pair<int, long long>> best(n);

  int ind = n - k;
  long long cur = 0;
  while (ind < n) cur += v[ind ++];

  best[n - k] = {n - k, cur};

  ind = n - 1;
  for (int i = n - k - 1; i >= 0; --i, --ind) {
    long long sum = cur - v[ind] + v[i];

    if (sum >= best[i + 1].second) {
      best[i] = {i, sum};
    }
    else {
      best[i] = best[i + 1];
    }

    cur = sum;
  }

  ind = 0;
  cur = 0;
  while (ind < k) cur += v[ind ++];

  long long mx = cur + best[k].second;
  int a = 0;
  int b = best[k].first;
  ind = 0;
  for (int i = k; i + k < n; ++i, ++ind) {
    long long sum = cur - v[ind] + v[i];
    if (sum + best[i + 1].second > mx) {
      a = i - k + 1;
      b = best[i + 1].first;
      mx = sum + best[i + 1].second;
    }
    cur = sum;
  }

  cout << a + 1 << " " << b + 1 << endl;
  return 0;
}