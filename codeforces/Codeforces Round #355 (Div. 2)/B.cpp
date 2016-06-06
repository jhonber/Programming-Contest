// http://codeforces.com/contest/677/problem/B

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() { IO
  int n, h, k;
  cin >> n >> h >> k;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  reverse(v.begin(), v.end());

  long long r = 0;
  long long ans = 0;
  while (!v.empty()) {
    long long cur = v.back();
    long long tot = r + cur;

    if (tot <= h) {
      v.pop_back();
      while (!v.empty() && tot + v.back() < h) {
        tot += v.back();
        v.pop_back();
      }

      ans += tot / k;
      r = tot % k;
    }
    else {
      ans ++;
      r = 0;
    }
  }

  ans += (r ? 1 : 0);
  cout << ans << endl;

  return 0;
}