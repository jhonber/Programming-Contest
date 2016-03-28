// http://codeforces.com/contest/652/problem/B

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  sort(v.begin(), v.end());

  vector<int> ans;
  int i, j;
  for (i = 0, j = n - 1; i < j; ++i, --j) {
    ans.push_back(v[i]);
    ans.push_back(v[j]);
  }

  if (ans.size() != n) ans.push_back(v[j]);

  for (int i = 0; i < n; ++i) cout << ans[i] << " ";

  return 0;
}