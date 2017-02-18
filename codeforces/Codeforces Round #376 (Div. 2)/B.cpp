// http://codeforces.com/contest/731/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  int ok = true;
  int last = v[0] % 2;
  for (int i = 1; i < n; ++i) {
    if (last) {
      if (!v[i]) {
        ok = false;
        break;
      }

      v[i] --;
    }

    last = v[i] % 2;
  }

  if (last != 0) ok = false;
  cout << (ok ? "YES" : "NO") << endl;

  return 0;
}