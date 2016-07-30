// http://codeforces.com/contest/702/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, m;
  cin >> n >> m;

  set<int> a, b;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    a.insert(t);
  }

  for (int i = 0; i < m; ++i) {
    int t;
    cin >> t;
    b.insert(t);
  }

  vector<int> v1(a.begin(), a.end());
  vector<int> v2(b.begin(), b.end());

  n = v1.size();
  m = v2.size();

  int ans = 0;

  for (int i = 0; i < n; ++i) {
    auto it = upper_bound(v2.begin(), v2.end(), v1[i]);
    int d1, d2;
    d1 = d2 = INT_MAX;

    if (it != v2.end())
      d1 = abs(v1[i] - *it);

    if (it != v2.begin()) {
      it --;
      d2 = abs(v1[i] - *it);
    }

    ans = max(ans, min(d1, d2));
  }

  cout << ans << endl;

  return 0;
}