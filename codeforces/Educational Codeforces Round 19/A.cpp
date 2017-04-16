// http://codeforces.com/contest/797/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, k;
  while (cin >> n >> k) {
    int cnt = 0;
    int div = 2;
    vector<int> ans;
    while (cnt < k && n > 1) {
      while (n % div == 0 && cnt < k) {
        n /= div;
        ans.push_back(div);
        cnt ++;
      }

      div ++;
    }

    if (n > 1) ans.push_back(n);
    if (cnt == k) {
      if (ans.size() > k) {
        ans[k - 1] *= ans[k];
      }
      for (int i = 0; i < k; ++i) cout << ans[i] << " "; cout << endl;
    }
    else cout << -1 << endl;

  }
  return 0;
}