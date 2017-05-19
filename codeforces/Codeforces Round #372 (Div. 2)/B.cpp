// http://codeforces.com/contest/716/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string s;

  while (cin >> s) {
    bool ok = false;
    for (int i = 0; i + 25 < s.size(); ++i) {
      set<char> all;
      int mark = 0;
      for (int j = 0; j < 26; ++j) {
        char cur = s[i + j];
        if (cur == '?') mark ++;
        else all.insert(cur);
      }

      if (all.size() + mark == 26) {
        vector<int> pos;
        for (int j = 0; j < 26; ++j) {
          if (s[i] == '?') pos.push_back(i);
          i ++;
        }

        for (int j = 0; j < 26; ++j) {
          char c = j + 'A';
          if (all.count(c) == 0) {
            s[pos.back()] = c;
            pos.pop_back();
          }
        }

        for (int j = 0; j < s.size(); ++j) if (s[j] == '?') s[j] = 'X';
        cout << s << endl;

        ok = true;
        break;
      }
    }

    if (!ok) cout << -1 << endl;
  }

  return 0;
}