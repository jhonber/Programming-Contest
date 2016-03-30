#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  char c;
  string s;
  while (cin >> c >> s) {
    if (c == '0' && s == "0") break;

    string ans;
    for (int i = 0; i < s.size(); ++i) if (s[i] != c) ans.push_back(s[i]);

    while (ans[0] == '0' && ans.size() > 1) ans.erase(0, 1);

    if (ans.size() == 0) cout << 0 << endl;
    else cout << ans <<endl;

  }

  return 0;
}