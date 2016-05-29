#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() { IO
  int n, m;
  while (cin >> n >> m) {
    if (n + m == 0) break;

    set<int> st;
    for (int i = 1; i <= n; ++i) st.insert(i);
    st.insert(-1);
    st.insert(INT_MAX);

    set<int> :: iterator it;
    for (int i = 0; i < m; ++i) {
      int l, r;
      cin >> l >> r;

      for (int j = l; j <= r; ++j) st.erase(j);

      it = st.upper_bound(r);
      int b = *it;
      it --;
      int a = *it;

      if (a == -1) cout << "* ";
      else cout << a << " ";

      if (b == INT_MAX) cout << "*";
      else cout << b;

      cout << endl;
    }

    cout << "-" << endl;
  }

  return 0;
}