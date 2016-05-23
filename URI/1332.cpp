#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " " << (x) << endl;

int main() {
  int n;
  cin >> n;

  while (n --> 0) {
    string s;
    cin >> s;

    vector<string> v = {"one", "two"};
    if (s.size() > 3) cout << 3 << endl;
    else {
      int a = 0;
      int b = 0;
      for (int i = 0; i < 3; ++i) {
        if (v[0][i] == s[i]) a ++;
        if (v[1][i] == s[i]) b ++;
      }

      if (a > b) cout << 1 << endl;
      else cout << 2 << endl;
    }
  }

  return 0;
}