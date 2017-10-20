// http://codeforces.com/contest/811/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() { IO
  int n, m;
  while (cin >> n >> m) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    for (int i = 0; i < m; ++i) {
      int l, r, p;
      cin >> l >> r >> p; l --; r --; p --;

      if (p > r || p < l) {
         cout << "Yes" << endl;
        continue;
      }

      int left = 0;
      int rigth = 0;

      while (l < p) {
        left += v[l] > v[p];
        l ++;
      }

      while (r > p) {
        rigth += v[r] < v[p];
        r --;
      }

      if (rigth == left) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }

  return 0;
}