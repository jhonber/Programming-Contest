// http://codeforces.com/contest/166/problem/C

#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, x;
  cin >> n >> x;

  bool found = false;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    if (v[i] == x) found = true;
  }

  if (!found) v.push_back(x);
  sort(v.begin(), v.end());

  int ans = INT_MAX;
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] == x) {
      int l = i;
      int r = (v.size() - i) - 1;
      int tot = 0;

      if (l == r) {
        ans = 0;
        break;
      }
      else if (l > r) {
        tot = l - r;
      }
      else {
        tot = (r - l) - 1;
      }

      ans = min(ans, tot);
    }
  }

  cout << ans + !found << endl;
  return 0;
}