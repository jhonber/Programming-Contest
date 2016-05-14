#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

int main() {
  int n, m;
  while (cin >> n >> m) {
    if (n + m == 0) break;

    int found = false;
    for (int i = 1; i <= m && !found; ++i) {
      int cur = i;
      long long step = 0;
      while (cur > 0 && !found) {
        for (int j = 0; j < cur; ++j) {
          if (step == n) {
            found = true;
            break;
          }

          step += cur;
        }

        cur --;
      }

      if (step == n) {
        found = true;
      }


    }

    cout << (found ? "possivel" : "impossivel") << endl;
  }

  return 0;
}