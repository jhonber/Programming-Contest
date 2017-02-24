// http://codeforces.com/contest/766/problem/B

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

  bool ok = false;
  for (int i = 2; i < v.size(); ++i) {
    if (v[i - 2] + v[i - 1] > v[i]) {
      ok = true;
      break;
    }
  }

  cout << (ok ? "YES" : "NO") << endl;
  return 0;
}