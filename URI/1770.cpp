#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    int ans = 0;
    set<int> st;
    for (int i = 0; i < m; ++i) {
      int a;
      cin >> a;

      if (st.size() == n)
        continue;

      st.insert(a);
      ans += v[a - 1];
    }

    if (st.size() == n) cout << ans << endl;
    else cout << -1 << endl;
  }

  return 0;
}