// http://codeforces.com/contest/814/problem/A

#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<int> a(n), b(m);
    int zeros = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      zeros += !a[i];
    }

    for (int i = 0; i < m; ++i) cin >> b[i];

    if (zeros > 1) cout << "Yes" << endl;
    else {
      if (zeros == 1) {
        for (int i = 0; i < n; ++i) if (!a[i]) a[i] = b[0];
      }

      bool ok = false;
      for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) {
          ok = true;
          break;
        }
      }

      cout << (ok ? "Yes" : "No") << endl;
    }
  }

  return 0;
}