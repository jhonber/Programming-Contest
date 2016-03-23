#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string s;
  while (getline(cin, s)) {
    int j = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (isalpha(s[i])) {
        if (j % 2 == 0) s[i] = (char)toupper(s[i]);
        else s[i] = (char)tolower(s[i]);
        j ++;
      }
      else s[i] = (char)s[i];
    }
    cout << s << endl;
  }

  return 0;
}
