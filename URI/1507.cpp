#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t;
  while (cin >> t) {
    while (t --> 0) {
      int q;
      string s;
      cin >> s >> q;

      string s2;
      for (int x = 0; x < q; ++x) {
        cin >> s2;

        int ind = 0;
        int paila = false;
        for (int i = 0; i < s2.size(); ++i) {
          int found = false;
          for (int j = ind; j < s.size(); ++j) if (s[j] == s2[i]) {
            found = true;
            ind = j + 1;
            break;
          }

          if (!found) {
            paila = true;
            break;
          }
        }

        if (paila) cout << "No" << endl;
        else cout << "Yes" << endl;
      }
    }
  }

  return 0;
}
