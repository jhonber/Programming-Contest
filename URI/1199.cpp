#include<bits/stdc++.h>
using namespace std;

string dec_to_hex(long long x) {
  stringstream ss;
  ss << std::hex << x;

  string xx = ss.str();
  for (int i = 0; i < xx.size(); ++i) xx[i] = toupper(xx[i]);
  return "0x" + xx;
}

long long hex_to_dec(string x) {
  long long xx;
  stringstream ss;
  ss << x;
  ss >> std::hex >> xx;

  return xx;
}

int main() {
  string s;
  while (cin >> s) {
    if (s == "-1") break;
    if (s.find("0x") != string::npos) {
      cout << hex_to_dec(s.substr(2)) << endl;
    }
    else {
      stringstream ss(s);
      long long x;
      ss >> x;
      cout << dec_to_hex(x) << endl;
    }
  }
  return 0;
}