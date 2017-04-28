// https://csacademy.com/contest/round-26/#task/limited-vocabulary
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, k;
  cin >> n >> k;

  int best = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    set<char> st;
    string s;
    cin >> s;

    for (int j = 0; j < s.size(); ++j) st.insert(s[j]);
    if (st.size() <= k && s.size() > ans) {
      ans = s.size();
    }
  }

  cout << (ans == 0 ? -1 : ans) << endl;

  return 0;
}
