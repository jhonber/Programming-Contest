#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string s;
  while (getline(cin, s)) {
    string bef;
    stringstream ss;
    ss << s;
    ss >> bef;

    int ans = 0;
    string cur;
    int f = false;

    while (ss >> cur) {
      if (tolower(cur[0]) == tolower(bef[0])) {
        f = true;
      }
      else {
        ans += f;
        f = false;
      }

      bef = cur;
    }

    ans += f;
    cout << ans << endl;
  }

  return 0;
}