#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, m;

  while (cin >> n >> m) {
    set<int> st;

    for (int i = 0; i < m; ++i) {
      int a;
      cin >> a;
      st.insert(a);
    }

    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;

      if (st.count(a) == 0) {
        cout << 1 << endl;
      }
      else {
        cout << 0 << endl;
      }
      st.insert(a);
    }
  }


  return 0;
}