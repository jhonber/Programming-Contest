#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string s;
  int n;
  while (cin >> s >> n) {
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) if (s[i] == 'W') ans ++;

    int i = 0;
    while (i < s.size()) {
      while (i < s.size() && s[i] == 'W') i ++;
      int cnt = 0;
      while (i < s.size() && s[i] == 'R') {
        cnt ++;
        i ++;
      }

      i ++;
      ans += ceil((double)cnt / n);
    }

    cout << ans << endl;
  }

  return 0;
}