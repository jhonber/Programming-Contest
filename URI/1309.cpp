#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string s, s2;
  while (cin >> s >> s2) {
    string ans = "$";

    int size = s.size();
    ans = ans + s.substr(0, size % 3);
    int i = size % 3;

    while (i < size) {
      ans = ans + (ans.size() > 1 ? "," : "") + s.substr(i, 3);
      i += 3;
    }

    string dec = s2;
    while (dec.size() < 2) {
      dec = "0" + s2;
    }

    dec = "." + dec;
    ans += dec;
    cout << ans << endl;
  }

  return 0;
}
