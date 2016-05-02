#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string s;

  while (getline(cin, s)) {
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '_') {
        if (cnt1 % 2 == 0) cout << "<i>";
        else cout << "</i>";
        cnt1 ++;
      }
      else if (s[i] == '*') {
        if (cnt2 % 2 == 0) cout << "<b>";
        else cout << "</b>";
        cnt2 ++;
      }
      else cout << s[i];
    }
    cout << endl;
  }

  return 0;
}
