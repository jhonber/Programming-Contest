#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t;
  cin >> t;

  long double x;
  int n, m;
  while (t --> 0) {
    cin >> n >> m;

    n *= 100;
    int ans = 0;
    for (int i = 0; i < m; ++i) {
      cin >> x;

      int p = round(x * 100);
      int tot = 0;
      while (tot * p <= n) tot ++;
      if (tot * p > n) tot --;

      if (tot > 0)
        ans = max(ans, n - (tot * p));
    }

    printf("%d.%02d\n", ans / 100, ans % 100);
  }

  return 0;
}