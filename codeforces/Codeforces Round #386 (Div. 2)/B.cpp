// http://codeforces.com/contest/746/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    string s;
    cin >> s;

    string ans;
    ans.push_back(s[0]);
    s.erase(s.begin());

    int t = 0;
    while (s.size() > 0) {
      if (n % 2 != 0) {
        if (t % 2 == 0) ans.insert(ans.begin(), s[0]);
        else ans.push_back(s[0]);
      }
      else {
        if (t % 2 == 0) ans.push_back(s[0]);
        else ans.insert(ans.begin(), s[0]);
      }

      s.erase(s.begin());
      t ++;
    }

    cout << ans << endl;
  }

  return 0;
}