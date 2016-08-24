// http://codeforces.com/contest/709/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

char prev(char c) {
  int a = c - 'a';
  if (a - 1 < 0) return 'z';
  return char((a - 1) + 'a');
}

int main() {
  string s;
  cin >> s;

  int f = true;
  for (int i = 0; i < s.size(); ++i) {
    char p = prev(s[i]);
    if (p < s[i]) {
      s[i] = p;
      f = false;
    }
    else if (!f) break;
  }

  if (f) {
    int i = s.size() - 1;
    while (i >= 0) {
      char p = prev(s[i]);
      if (p < s[i]) {
        s[i] = p;
        f = false;
        break;
      }
      i --;
    }
  }

  if (f) {
    int l = s.size() - 1;
    s[l] = prev(s[l]);
  }

  cout << s << endl;
  return 0;
}