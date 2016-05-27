#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;

    long long ans = 0, p;
    for (int i = 1; i <= n; ++i) {
      p = (n - i) + 1;
      ans += p * p;
    }

    cout << ans << endl;
  }

  return 0;
}