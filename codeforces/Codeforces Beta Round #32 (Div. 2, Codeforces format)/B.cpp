// http://codeforces.com/contest/32/problem/B

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(NULL); cin.tie(false);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string s;
  cin >> s;

  string ans;
  for (int i = 0; i < s.size(); ) {
    if (s[i] == '.') {
      ans += "0";
      i ++;
    }
    else {
      if (i + 1 < s.size() && s[i + 1] == '.') {
        ans += "1";
        i += 2;
      }
      else {
        ans += "2";
        i += 2;
      }
    }
  }

  cout << ans;
  return 0;
}