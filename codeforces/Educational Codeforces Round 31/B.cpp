// http://codeforces.com/contest/884/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, x;
  while (cin >> n >> x) {
    int tot = 0;
    int t = 0;
    for (int i = 0; i < n; ++i) {
      cin >> t;
      tot += t;
    }

    if (n == 1) {
      if (x == t) cout << "YES" << endl;
      else cout << "NO" << endl;
      continue;
    }

    if (x == tot + n - 1) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  return 0;
}