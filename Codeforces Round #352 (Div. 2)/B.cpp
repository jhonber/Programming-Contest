// http://codeforces.com/contest/672/problem/B

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  set<char> st;
  for (int i = 0; i < n; ++i) {
    st.insert(s[i]);
  }

  if (s.size() > 26) {
    cout << -1 << endl;
  }
  else {
    int ans = n - (int)st.size();
    cout << ans << endl;
  }

  return 0;
}