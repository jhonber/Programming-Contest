// http://codeforces.com/contest/448/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int f (int l, int r, vector<int> &v) {
  if (l == r) return 1;

  int mm = INT_MAX;
  for (int i = l; i <= r; ++i) mm = min(mm, v[i]);
  int ans = mm;

  for (int i = l; i <= r; ++i) v[i] -= mm;

  int last = l;
  for (int i = l; i <= r; ++i) {
    if (!v[i]) last = i + 1;
    else if (!v[i + 1] || i == r) {
      ans += f(last, i, v);
      last = i + 1;
    }
  }

  return min(r - l + 1, ans);
}

int main() {
  int n;
  while (cin >> n) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    cout << f (0, n - 1, v) << endl;
  }

  return 0;
}