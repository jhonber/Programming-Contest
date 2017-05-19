// http://codeforces.com/contest/716/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, c;
  while (cin >> n >> c) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    reverse(v.begin(), v.end());

    int ans = 0;
    for (int i = 1; i < n; ++i) {
      if (v[i - 1] - v[i] <= c) ans ++;
      else break;
    }

    cout << ans + 1 << endl;
  }

  return 0;
}