// http://codeforces.com/contest/673/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, m;
  cin >> n >> m;

  if (m == 0) {
    cout << n - 1 << endl;
    return 0;
  }

  int mx = -1;
  int mm = INT_MAX;

  int paila = false;
  set<int> a, b;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;

    if (x > y) swap(x, y);
    if (b.count(x) > 0 || a.count(y) > 0) {
      paila = true;
    }

    mx = max(x, mx);
    mm = min(y, mm);
    a.insert(x);
    b.insert(y);
  }

  if (paila || mm < mx) {
    cout << 0 << endl;
    return 0;
  }


  int r = 0;
  for (int i = 1; i <= n; ++i) {
    if (b.count(i) == 0 && a.count(i) == 0 && i < mm && i > mx) {
      r ++;
    }
  }

  cout << r + 1 << endl;
  return 0;
}