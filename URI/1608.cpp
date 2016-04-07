#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  long long t;
  cin >> t;

  while (t --> 0) {
    long long d, ii, b;
    cin >> d >> ii >> b;

    vector<long long> prices(ii);
    for (long long i = 0; i < ii; ++i) {
      cin >> prices[i];
    }

    long long ans = 0;
    for (long long i = 0; i < b; ++i) {
      long long c;
      cin >> c;

      long long price = 0;
      for (long long j = 0; j < c; ++j) {
        long long a, b;
        cin >> a >> b;
        price += prices[a] * b;
      }

      long long amo1 = d / price;
      long long amo2 = ceil((double)d / price);
      if (amo2 * price <= d) {
        amo1 = max(amo1, amo2);
      }

      ans = max(amo1, ans);
    }

    cout << ans << endl;
  }
  return 0;
}