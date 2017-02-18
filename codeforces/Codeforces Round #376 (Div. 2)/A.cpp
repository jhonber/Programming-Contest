// http://codeforces.com/contest/731/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string s;
  cin >> s;

  char last = 'a';
  int ans = 0;
  for (int i = 0; i < s.size(); ++i) {
    int diff = abs(s[i] - last);
    ans += min(diff, 26 - diff);
    last = s[i];
  }

  cout << ans << endl;

  return 0;
}