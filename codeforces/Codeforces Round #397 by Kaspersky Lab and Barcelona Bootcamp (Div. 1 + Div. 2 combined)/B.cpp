// http://codeforces.com/contest/765/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string s;
  cin >> s;

  bool ok = true;
  int next = 0;
  while (next < 26 && s.size() > 0) {
    int cur = s[0] - 'a';
    if (cur != next) {
      ok = false;
      break;
    }

    string s2;
    for (int i = 0; i < s.size(); ++i) if ((int)(s[i] - 'a') != next) {
      s2.push_back(s[i]);
    }

    s = s2;
    next ++;
  }

  ok = !s.size();

  cout << (ok ? "YES" : "NO") << endl;

  return 0;
}