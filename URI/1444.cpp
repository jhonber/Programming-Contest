#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() { IO
  int n;

  int memo[111000];
  memset(memo, -1, sizeof memo);
  while (cin >> n) {
    if (!n) break;

    if (memo[n] != -1) {
      cout << memo[n] << endl;
      continue;
    }

    int ans = 0;
    while (n > 1) {
      int tot = 0;
      int three = n / 3;

      if (n % 3 == 1) {
        three --;
        n -= three * 3;
        ans += three;
        tot += three;
      }

      if (n % 3 == 0 || n % 3 == 2 && n > 0) {
        n -= three * 3;
        ans += three;
        tot += three;
      }

      if (n % 2 == 0 && n > 0) {
        int two = n / 2;
        n -= two;
        ans += two;
        tot += two;
      }
      n = tot;
    }

    cout << ans << endl;
  }

  return 0;
}