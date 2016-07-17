// http://codeforces.com/contest/665/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

char next (char c, char d) {
  string s = "abcdefghijklmnopqrstuvwxyz";
  int i = 0;
  for (; i < s.size(); ++i) if (c != s[i] && d != s[i]) return s[i];
}

int main() {
  string s;
  while (cin >> s) {
    int n = s.size();

    s.push_back('*');
    int i = 0;
    while (i < n) {
      int cnt = 1;
      int j = i;
      char c = s[i];
      char d = s[i - 1];
      while (i + 1 < n && s[i] == s[i + 1]) {
        cnt ++;
        i ++;
      }

      if (cnt > 1) {
        if (cnt % 2 == 0) {
          while (j < i && j < n) {
            s[j] = next(c, d);
            j += 2;
          }
        }
        else {
          j ++;
          while (j < i && j < n) {
            s[j] = next(c, d);
            j += 2;
          }
        }
      }
      else i ++;
    }

    cout << s.substr(0, n) << endl;
    for (int i = 1; i < n; ++i) if (s[i - 1] == s[i]) assert(false);
  }

  return 0;
}