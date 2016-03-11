#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  double a;
  for (int i = 0; i < n; ++i) {
    cin >> a;

    int ans = 0;
    while (a > 1.0) {
      a /= 2.0;
      ans ++;
    }

    cout << ans << " dias" << endl;
  }

  return 0;
}
