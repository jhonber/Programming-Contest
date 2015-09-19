// http://codeforces.com/contest/94/problem/A

#include<bits/stdc++.h>
using namespace std;

int main() {
  string line;
  cin >> line;

  map<string, int> mapa;
  for (int i = 0; i < 10; ++i) {
    string s;
    cin >> s;
    mapa[s] = i;
  }

  for (int i = 0; i < line.size(); i += 10) {
    string s = line.substr(i, 10);
    cout << mapa[s];
  }

  return 0;
}