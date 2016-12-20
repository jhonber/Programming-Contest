#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main () {
  int a, p;
  cin >> a >> p;

  int ans = 1;
  int t, bef, cur;
  for (int i = 0; i < a; ++i) {
    cin >> t;

    cin >> bef;
    double tot = bef;
    for (int j = 1; j < t; ++j) {
      cin >> cur;

      if (bef > cur) tot += p - bef + cur;
      else tot += cur - bef;

      bef = cur;
    }

    ans = max(ans, (int)ceil(tot / p));
  }

  cout << ans << endl;

  return 0;
}