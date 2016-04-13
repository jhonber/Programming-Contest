#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

bool check(string x) {
  int s1 = x.size();
  set<char> st;

  for (int i = 0; i < s1; ++i) st.insert(x[i]);

  if ((int)st.size() != s1) return false;
  return true;
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    int ans = 0;
    stringstream ss;
    string s;
    for (int i = n; i <= m; ++i) {
      ss << i;
      ss >> s;
      if (check(s)) ans ++;
      ss.clear();
    }

    cout << ans << endl;
  }

  return 0;
}
