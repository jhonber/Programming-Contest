// http://codeforces.com/contest/787/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;

    set<int> a, b;
    for (int j = 0; j < x; ++j) {
      int t;
      cin >> t;

      if (t < 0) b.insert(abs(t));
      else a.insert(t);
    }

    bool ok = false;
    for (auto j: a) {
      if (b.count(j) > 0) {
        ok = true;
      }
    }

    if  (!ok) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
  return 0;
}