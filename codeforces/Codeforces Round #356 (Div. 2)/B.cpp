// http://codeforces.com/contest/680/problem/B

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, a;
  cin >> n >> a; a --;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  int ans = v[a];
  v[a] = -1;

  int lim = min(a, (n - a) - 1);
  for (int i = 1; i <= lim; ++i) {

    if (v[a + i] && v[a - i]) {
      ans += 2;
    }
    v[a + i] = v[a - i] = -1;
  }

  for (int i = 0; i < n; ++i) if (v[i] != -1) ans += v[i];
  cout << ans << endl;
  return 0;
}