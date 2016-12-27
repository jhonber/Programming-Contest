#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main () {
  string s;
  getline(cin, s);
  while (getline(cin, s)) {
    int ind = 0;
    while (true) {
      ind = s.find("oulupukk", ind);
      if (ind == string::npos) break;
      s[ind - 1] = 'J';
      s[ind + 8] = 'i';
      ind ++;
    }

    cout << s << endl;
  }

  return 0;
}