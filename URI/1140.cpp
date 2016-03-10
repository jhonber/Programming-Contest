#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string line;
  while (getline(cin, line)) {
    if (line == "*") break;

    stringstream ss;
    ss << line;

    int good = true;
    string s;
    ss >> s;
    char c = tolower(s[0]);
    while (ss >> s) {
      if (tolower(s[0]) != c) {
        good = false;
        break;
      }
    }

    cout << (good ? "Y" : "N") << endl;
  }

  return 0;
}