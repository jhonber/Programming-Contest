#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  string s;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    string s2;

    for (int j = 0; j < s.size(); ++j) if (s[j] != '.') s2 += s[j];
    s = s2;

    int ans = 0;
    while (true) {
      int ind = s.find("<>");
      if ( s.find("<>") != string::npos) {
        s.erase(ind, 2);
        ans ++;
      }
      else break;
    }
    cout << ans << endl;
  }

  return 0;
}