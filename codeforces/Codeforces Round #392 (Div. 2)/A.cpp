// http://codeforces.com/contest/758/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  int mmax = *max_element(v.begin(), v.end());
  int ans = 0;
  for (int i = 0; i < n; ++i) ans += mmax - v[i];

  cout << ans << endl;

  return 0;
}