// http://codeforces.com/contest/598/problem/B

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);

string shift (string s, int k) {
  int n = s.size();
  string ans = s;

  for (int i = 0; i < n; ++i) ans[i] = s[(i + k) % n];
  return ans;
}


int main () { IO
  string s;
  cin >> s;

  int size = s.size();
  int q; cin >> q;

  while (q --> 0) {
    int l,r,k;
    cin >> l >> r >> k;
    l --; r--;

    int n = (r - l) + 1;
    int pos = n - (k % n);

    string s2 = s;
    string t = shift(s.substr(l, n), pos);
    s2 = s.substr(0,l) + t + s.substr(r + 1, (size - 1) - r );
    s = s2;
  }

  cout << s << endl;

  return 0;
}