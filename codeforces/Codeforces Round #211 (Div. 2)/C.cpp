// http://codeforces.com/contest/363/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string s;
  cin >> s;

  int n = s.size();
  string s2;
  int i = 1;
  s2.push_back(s[0]);

  while (i < n) {
    char last = s[i - 1];
    s2.push_back(s[i]);
    if (s[i] == last) {
      while (i < n && s[i] == last) i ++;
      i --;
    }
    i ++;
  }

  s = s2;

  for (int i = 0; i < s.size(); ++i) {
    if (i + 3 <= s.size() && s[i] == s[i + 1] && s[i + 2] == s[i + 3]) {
      s[i + 2] = '*';
    }
  }

  for (int i = 0; i < s.size(); ++i) if (s[i] != '*') cout << s[i]; cout << endl;

  return 0;
}