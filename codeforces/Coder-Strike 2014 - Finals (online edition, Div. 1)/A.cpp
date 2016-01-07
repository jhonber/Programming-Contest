// http://codeforces.com/contest/420/problem/A

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string s;
  cin >> s;

  string good = "AHIMOTUVWXY";
  string s2 = s;
  reverse(s2.begin(), s2.end());

  int bad = false;
  for (int i = 0; i < s.size(); ++i) {
    int f = false;
    for (int j = 0; j < good.size(); ++j) {
      if (s[i] == good[j]) f = true;
    }
    if (!f) bad = true;
  }
  if (!bad && s2 == s) cout << "YES";
  else cout << "NO";
  return 0;
}