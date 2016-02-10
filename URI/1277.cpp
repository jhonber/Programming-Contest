#include<bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;

    vector<string> v(n);
    for (int j = 0; j < n; ++j) {
      cin >> v[j];
    }

    int cnt = 0;
    for (int j = 0; j < n; ++j) {
      string s;
      cin >> s;

      double tot = 0;
      double lazy = 0;
      for (int k = 0; k < s.size(); ++k) {
        if (s[k] == 'M') continue;
        if (s[k] == 'A') lazy ++;
        tot ++;
      }

      double good = ((tot - lazy) * 100.0) / tot;
      if (good < 75.0) {
        if (cnt > 0) cout << " ";
        cout << v[j];
        cnt ++;
      }
    }
    cout << endl;
  }

  return 0;
}