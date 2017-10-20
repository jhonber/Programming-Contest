// http://codeforces.com/contest/863/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

bool is_pal (string s) {
  int t = s.size();
  for (int i = 0; i < t / 2; ++i) {
    if (s[i] != s[t - (i + 1)]) return false;
  }

  return true;
}

int main() {
  string t;
  while (cin >> t) {
    int zeros = 0;
    string s = t;
    while (s.back() == '0') {
      zeros ++;
      s.pop_back();
    }

    while (zeros --> 0) t = "0" + t;
    if (is_pal(t)) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  return 0;
}