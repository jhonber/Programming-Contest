// http://codeforces.com/contest/803/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    vector<int> v(n), ans(n, INT_MAX);

    for (int i = 0; i < n; ++i) cin >> v[i];

    for (int i = 0; i < n; ++i) {
      if (!v[i]) {
        ans[i] = 0;
        int j = i + 1;
        int cnt = 1;
        while (j < n && v[j] != 0) {
          ans[j] = cnt ++;
          j ++;
        }
      }
    }

    for (int i = n - 1; i >= 0; --i) {
      if (!v[i]) {
        ans[i] = 0;
        int j = i - 1;
        int cnt = 1;
        while (j >= 0 && v[j] != 0) {
          ans[j] = min(ans[j], cnt ++);
          j --;
        }
      }
    }

    for (int i = 0; i < n; ++i) cout << ans[i] << " "; cout << endl;

  }
  return 0;
}