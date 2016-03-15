// http://codeforces.com/contest/624/problem/B

#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    long long ans = 0;
    set<int> ready;
    while (v.size() > 0) {
      sort(v.begin(), v.end());
      reverse(v.begin(), v.end());

      if (ready.count(v[0]) == 0) {
        ready.insert(v[0]);
        ans += v[0];
        v.erase(v.begin());
      }
      else {
        v[0] --;
      }

      if (v[0] <= 0) v.erase(v.begin());
    }
    cout << ans << endl;
  }

  return 0;
}