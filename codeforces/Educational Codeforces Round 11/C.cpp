// http://codeforces.com/contest/660/problem/C

#include<bits/stdc++.h>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(null);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, k;
  while (cin >> n >> k) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    int zeros = 0;
    int mx = 0;
    int ind = 0;
    int i = 0, j = 0;

    while (i < n && j < n) {
      while (zeros <= k && j < n) {
        if (!v[j] && zeros + 1 > k) break;
        zeros += !v[j];
        j ++;
      }

      int l = j - i;
      if (l > mx) {
        ind = i;
        mx = l;
      }

      while (i < n && v[i]) i ++;
      i ++;
      zeros --;
    }

    int last = ind;
    while (k > 0 && ind < n) {
      if (!v[ind]) {
         v[ind] = 1;
         k --;
      }

      ind ++;
    }

    cout << mx << endl;
    for (int i = 0; i < n; ++i) cout << v[i] << " "; cout << endl;
  }

  return 0;
}