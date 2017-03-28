// http://codeforces.com/contest/792/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  sort(v.begin(), v.end());

  map<int, int> cnt;
  int t = abs(v[0] - v[n - 1]);
  if (n > 2) cnt[t] ++;

  for (int i = 1; i < n; ++i) {
    t = abs(v[i] - v[i - 1]);
    cnt[t] ++;
  }

  auto ans = cnt.begin();
  cout << ans->first << " " << ans->second << endl;

  return 0;
}