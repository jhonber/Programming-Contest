// http://codeforces.com/contest/609/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(NULL); cin.tie(NULL);

int main() { //IO
  int n;
  while (cin >> n) {
    long long tot = 0;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      tot += v[i];
    }

    sort(v.begin(), v.end());

    long long mid = tot / n;
    long long r = tot % n;
    long long ans = 0;

    long long cnt = 0;

    for (int i = 0; i < n; ++i) {
      if (i < n - r) {
        if (v[i] > mid) cnt += v[i] - mid;
      }
      else {
        if (v[i] > mid + 1) cnt += v[i] - (mid + 1);
      }
    }

    for (int i = 0; i < n && cnt > 0; ++i) {
      if (i < n - r) {
        int t = abs(v[i] - mid);
        ans += t;
        cnt -= t;
      }
      else {
        int t = abs(v[i] - (mid + 1));
        ans += t;
        cnt -= t;
      }
    }

    cout << ans << endl;
  }

  return 0;
}