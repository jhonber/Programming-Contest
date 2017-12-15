#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
#ifdef ONLINEJUDGE
  ios_base::sync_with_stdio(0); cin.tie(0);
#endif

  int n, m;
  cin >> n >> m;

  int a, b;
  vector<int> times(n + 1, 0);
  vector<int> l(m), r(m);
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    l[i] = a;
    r[i] = b;
    a --;
    times[a] ++;
    times[b] --;
  }

  int zeros = 0;
  set<int> uniq;
  int acum = 0;
  for (int i = 0; i < n; ++i) {
    acum += times[i];
    if (acum == 1) uniq.insert(i + 1);
    if (acum == 0) zeros ++;
  }

  vector<int> ans(m, 0);
  for (int i = 0; i < m && uniq.size() > 0; ++i) {
    while (uniq.size() > 0) {
      auto lw = uniq.lower_bound(l[i]);
      if (lw != uniq.end() && *lw >= l[i] && *lw <= r[i]) {
        uniq.erase(lw);
        ans[i] ++;
      }
      else break;
    }
  }

  for (int i = 0; i < m; ++i) cout << ans[i] + zeros << " ";cout << endl;

  return 0;
}
