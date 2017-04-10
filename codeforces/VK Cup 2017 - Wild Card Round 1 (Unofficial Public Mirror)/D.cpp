// http://codeforces.com/contest/795/problem/D

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, l, r;
  cin >> n >> l >> r;
  l --;

  vector<int> v1(n), v2(n);
  for (int i = 0; i < n; ++i) cin >> v1[i];
  for (int i = 0; i < n; ++i) cin >> v2[i];

  sort(v1.begin() + l, v1.begin() + r);
  sort(v2.begin() + l, v2.begin() + r);

  bool ok = true;
  for (int i = 0; i < n; ++i) {
    if (v1[i] != v2[i]) {
      ok = false;
      break;
    }
  }

  cout << (ok ? "TRUTH" : "LIE") << endl;
  return 0;
}