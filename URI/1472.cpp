#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];


    set<int> st;
    st.insert(v[0]);
    int mx = v[0];
    for (int i = 1; i < n; ++i) {
      v[i] += v[i - 1];
      st.insert(v[i]);
      mx = max(v[i], mx);
    }

    if (mx % 3 != 0) {
      cout << 0 << endl;
      continue;
    }

    int ans = 0;
    int d = mx / 3;
    for (int i = 0; i < n; ++i) {
      int a = v[i];
      int b = a + d;
      int c = b + d;

      if (st.count(a) > 0 && st.count(b) > 0 && st.count(c) > 0)
        ans ++;
    }

    cout << ans << endl;
  }

  return 0;
}