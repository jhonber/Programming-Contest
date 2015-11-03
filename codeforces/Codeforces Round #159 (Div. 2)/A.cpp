// http://codeforces.com/contest/257/problem/A

#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  if (k >= m) {
    cout << 0;
    return 0;
  }

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());

  int used = 0;
  for (int i = 0; i < n && m > 0; ++i) {
    if (k >= m) {
      m = 0;
      break;
    }

    k --;
    m -= v[i];
    if (k < 0) m ++;
    used ++;
  }

  if (m > 0) cout << -1;
  else cout << used;

  return 0;
}