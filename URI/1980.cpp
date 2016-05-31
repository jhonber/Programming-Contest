#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  long long f[16];
  f[1] = 1;
  for (int i = 2; i < 16; ++i) {
    f[i] = f[i - 1] * i;
  }

  string s;
  while (cin >> s) {
    if (s == "0") break;

    set<char> st;
    for (int i = 0; i < s.size(); ++i) st.insert(s[i]);

    int n = st.size();
    cout << f[n] << endl;
  }

  return 0;
}