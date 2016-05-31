#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int q, d, p;

  while (cin >> q >> d >> p) {
    if (!q) break;

    int ans = d * (p * q) / (p - q);
    cout << ans << " pagina" << (ans > 1 ? "s" : "") << endl;
  }

  return 0;
}