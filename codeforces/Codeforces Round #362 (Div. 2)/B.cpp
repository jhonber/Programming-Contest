// http://codeforces.com/contest/697/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
  string s, a, d, b;
  while (cin >> s) {
    int p = s.find('.');
    int e = s.find('e');

    a = s.substr(0, p);
    d = s.substr(p + 1, e - (p + 1));
    b = s.substr(e + 1);

    string ans = a + d;

    int m = atoi(b.c_str());

    if (m < d.size()) {
      ans.insert(a.size() + (m - a.size()) + 1, ".");
    }
    else if (m > d.size()) {
      m -= d.size();
      while (m --> 0) ans.push_back('0');
    }

    if (ans.back() == '0' && ans.size() > 1) {
      ans.pop_back();
      if (ans.back() == '.') ans.pop_back();
      else ans.push_back('0');
    }

    cout << ans << endl;
  }

  return 0;
}