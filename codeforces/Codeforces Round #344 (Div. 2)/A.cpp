// http://codeforces.com/contest/631/problem/A

#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  vector<int> v(n), vv(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  for (int i = 0; i < n; ++i) cin >> vv[i];

  vector<int> p1(n + 1), p2(n + 1);
  p1[0] = p2[0] = 0;

  for (int i = 1 ; i <= n; ++i) p1[i] = p1[i - 1] | v[i - 1];
  for (int i = 1 ; i <= n; ++i) p2[i] = p2[i - 1] | vv[i - 1];

  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    long long tmp = 0;
    for (int j = i; j <= n; ++j) {
      tmp = (p1[j] - p1[i - 1]) + (p2[j] - p2[i - 1]);
      ans = max(tmp, ans);
    }
  }

  cout << ans << endl;

  return 0;
}