// http://codeforces.com/contest/43/problem/B

#include<bits/stdc++.h>
using namespace std;

int main() {
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);

  map<char, int> mapa;
  for (int i = 0; i < s1.size(); ++i) {
    mapa[s1[i]] ++;
  }

  bool good = true;
  for (int i = 0; i < s2.size(); ++i) {
    if (s2[i] == ' ') continue;
    if (mapa[s2[i]] == 0) {
      
      good = false;
      break;
    }
    mapa[s2[i]] --;
  }

  cout << (good ? "YES" : "NO") << endl;
  return 0;
}