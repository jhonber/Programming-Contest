#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(NULL); cie.tie(false);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int TC;
  cin >> TC;

  while (TC --> 0) {
    int t;
    cin >> t;

    vector<int> v(12);
    for (int i = 0; i < 12; ++i) cin >> v[i];

    int ans = 0;
    for (int i = 1; i < 11; ++i) {
      for (int j = i; j < 11; ++j) {
        int mx = INT_MAX;
        for (int k = i; k <= j; ++k) mx = min(v[k], mx);
        if (mx > v[i - 1] && mx > v[j + 1]) ans ++;
      }
    }
    cout << t << " " <<  ans << endl;
  }

  return 0;
}
