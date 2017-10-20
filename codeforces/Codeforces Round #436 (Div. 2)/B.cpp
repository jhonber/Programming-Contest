// http://codeforces.com/contest/864/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int check (string s) {
  set<char> st;
  for (int i = 0; i < s.size(); ++i) {
    st.insert(s[i]);
    if (isupper(s[i])) return 0;
  }

  return st.size();
}

int main() {
  int n;
  while (cin >> n) {
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 1; i + j <= n; ++j) {
        string sub = s.substr(i, j);
        ans = max(ans, check(sub));
      }
    }

    cout << ans << endl;
  }

  return 0;
}