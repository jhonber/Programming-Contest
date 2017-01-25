// http://codeforces.com/contest/339/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

bool go (int diff, int last, int m, string &s, vector<int> &rez) {
  if (m == 0) return true;

  bool ans = false;
  for (int j = diff + 1; j <= s.size(); ++j) {
    if (s[j - 1] == '1' && j != last) {
      ans = go(j - diff, j, m - 1, s, rez);
      if (ans) {
        rez.push_back(j);
        return ans;
      }
    }
  }

  return ans;
}

int main() {
  string s;
  cin >> s;

  int m;
  cin >> m;

  vector<int> ans;
  if (go(0, 0, m, s, ans)) {
    cout << "YES" << endl;
    for (int j = m - 1; j >= 0; --j) cout << ans[j] << " "; cout << endl;
    return 0;
  }

  cout << "NO" << endl;
  return 0;
}