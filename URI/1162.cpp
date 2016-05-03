#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t;
  cin >> t;

  while (t --> 0) {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    int ans = 0;
    int mx = n;
    while (true) {
      int f = true;
      for (int i = 0; i < n; ++i) {
        if (v[i] != i + 1) f = false;
      }

      if (f) break;

      for (int i = 0; i < n; ++i) {
        if (v[i] == mx) {
          while (i + 1 < mx) {
            swap(v[i], v[i + 1]);
            ans ++;
            i ++;
          }
          break;
        }
      }

//      for (int i = 0; i < n; ++i) cout << v[i] << " "; cout << endl;

      mx --;
    }

    cout << "Optimal train swapping takes " << ans << " swaps." << endl;
  }

  return 0;
}