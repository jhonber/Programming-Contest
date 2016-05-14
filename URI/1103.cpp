#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

int main() {
  int h1, h2, m1, m2;

  while (cin >> h1 >> m1 >> h2 >> m2) {
    if (h1 + h2 + m1 + m2 == 0) break;

    int ans = 0;
    int f = true;
    int i = h1;
    int j = m1;

    while (f) {
      for ( ; i < 24 && f; ++i) {
        for ( ; j < 60; ++j) {
          if (i == h2 && j == m2) {
            f = false;
            break;
          }
          ans ++;
        }
        j = 0;
      }
      i = 0;
    }

    cout << ans << endl;
  }
  return 0;
}