#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;

    int paila = false;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; ++i) {
      int a, b;
      cin >> a >> b;

      int ind = i + b;
      if (ind < 0 || ind >= n) paila = true;
      else if (ans[ind] > 0) paila = true;
      else ans[ind] = a;
    }

    if (paila) cout << -1 << endl;
    else {
      cout << ans[0];
      for (int i = 1; i < ans.size(); ++i) cout << " " << ans[i];
      cout << endl;
    }
  }

  return 0;
}