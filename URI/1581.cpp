#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t;
  cin >> t;

  while (t --> 0) {
    int n;
    cin >> n;

    set<string> st;
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;

      st.insert(s);
    }

    if (st.size() == 1) {
      cout << *st.begin() << endl;
    }
    else cout << "ingles" << endl;

  }

  return 0;
}