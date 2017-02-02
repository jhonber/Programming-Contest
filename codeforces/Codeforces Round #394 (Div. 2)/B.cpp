// http://codeforces.com/contest/761/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, l;
  cin >> n >> l;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];

  int lim = 333;
  while (lim --> 0) {
    bool ok = true;
    for (int j = 0; j < n; ++j) {
      a[j] ++;
      if (a[j] == l) a[j] = 0;
    }

    vector<int> tmp = a;
    for (int j = 0; j < n; ++j) {
      tmp.insert(tmp.begin(), tmp.back());
      tmp.pop_back();

      bool ok = true;
      for (int k = 0; k < n; ++k) if (tmp[k] != b[k]) {
        ok = false;
        break;
      }

      if (ok) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }

  cout << "NO" << endl;
  return 0;
}