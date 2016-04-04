#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;

  vector<int> f;
  int cnt = 1;
  for (int i = 1; i <= 9; ++i) {
    cnt *= i;
    f.push_back(cnt);
  }

  while (cin >> n) {
    int ans = 0;
    for (int i = f.size() - 1; i >= 0 && n > 0; --i) {
      int t = n / f[i];
      if (t > 0) ans += t;
      n -= (t * f[i]);
    }

    cout << ans << endl;
  }

  return 0;
}