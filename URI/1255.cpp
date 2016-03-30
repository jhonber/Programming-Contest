#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  string s;
  getline(cin, s);
  n = atoi(s.c_str());

  while (n --> 0) {
    getline(cin, s);

    map<char, int> mapa;
    for (int i = 0; i < s.size(); ++i) {
      if (!isalpha(s[i])) continue;
      char c = tolower(s[i]);
      mapa[c] ++;
    }

    int mx = 0;
    for (auto i : mapa) {
      mx = max(mx, i.second);
    }

    for (auto i : mapa) if (i.second == mx) {
      cout << i.first;
    }
    cout << endl;
  }

  return 0;
}