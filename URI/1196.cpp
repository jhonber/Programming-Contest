#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  vector<string> v = {"`1234567890-=", "qwertyuiop[]\\", "asdfghjkl;'", "zxcvbnm,./"};

  string s;
  while (getline(cin, s)) {
    string ans;
    for (int k = 0; k < s.size(); ++k) {
      if (s[k] == ' ') {
        ans.push_back(' ');
        continue;
      }

      int found = false;
      for (int i = 0; i < v.size() && !found; ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
          if (v[i][j] == tolower(s[k])) {
            ans.push_back(toupper(v[i][j - 1]));
            found = false;
            break;
          }
        }
      }
    }
    cout << ans << endl;
  }

  return 0;
}