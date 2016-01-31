#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m) {
    if (n + m == 0) break;

    int good = false;
    for (int i = 0; i < n; ++i) {
      set<int> st;
      for (int j = 0; j < m; ++j) {
        int x;
        cin >> x;
        st.insert(x);
      }

      if (st.size() == 1 && *st.begin() > 0) good = true;
    }

    cout << (good ? "yes" : "no") << endl;
  }

  return 0;
}
