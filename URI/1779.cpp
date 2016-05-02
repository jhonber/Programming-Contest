#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int tc;
  cin >> tc;

  for (int t = 1; t <= tc; ++t) {
    int n;
    cin >> n;

    vector<int> v(n);
    int mmax = 0;
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      mmax = max(mmax, v[i]);
    }

    int ans = 1;
    for (int i = 0; i < n; ) {
      if (v[i] == mmax) {
        int tot = 0;
        while (i < n && v[i] == mmax) {
          i ++;
          tot ++;
        }

        ans = max(ans, tot);
      }
      else i ++;
    }

    cout << "Caso #" << t << ": " << ans << endl;
  }

  return 0;
}