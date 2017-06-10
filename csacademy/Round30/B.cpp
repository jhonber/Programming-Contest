// https://csacademy.com/contest/virtual6147/task/jokers/

#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  set<int> all;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;

    all.insert(t);
  }

  int ans = 0;
  int lim = k;
  while (lim <= 1000) {
    int r = m;
    bool ok = true;
    int tot = k;
    int t = lim;
    while (tot --> 0) {
      if (all.count(t) == 0) {
        if (!r) {
          ok = false;
          break;
        }
        else r --;
      }
      t --;
    }

    ans += ok;
    lim ++;
  }

  cout << ans << endl;

  return 0;
}
