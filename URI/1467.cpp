#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string a, b, c;
  while (cin >> a >> b >> c) {

    string s;
    s = a + b + c;

    string ans;
    if (s == "000" || s == "111") ans = "*";
    else if (s == "011" || s == "100") ans = "A";
    else if (s == "101" || s == "010") ans = "B";
    else if (s == "001" || s == "110") ans = "C";

    cout << ans << endl;
  }

  return 0;
}