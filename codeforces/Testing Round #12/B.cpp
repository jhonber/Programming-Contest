// http://codeforces.com/contest/597/problem/B

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector< pair<int, int> > v(n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    v[i] = make_pair(b, a);
  }

  sort(v.begin(), v.end());

  int ans = 1;
  int last = v[0].first;
  for (int i = 1; i < n; ++i) {
    if (last < v[i].second) {
      last = v[i].first;
      ans ++;
    }
  }

  cout << ans;
  return 0;
}