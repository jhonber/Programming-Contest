// http://codeforces.com/contest/837/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    string s;
    int ans = 0;
    while (cin >> s) {
      int cnt = 0;
      for (int i = 0; i < s.size(); ++i) {
        if (isupper(s[i])) cnt ++;
      }
      ans = max(cnt, ans);
    }

    cout << ans << endl;
  }
  return 0;
}