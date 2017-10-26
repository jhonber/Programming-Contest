// http://codeforces.com/contest/877/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
  string s;
  while (cin >> s) {
    int n = s.size();
    vector<int> lasta(n + 1, 0);
    vector<int> lastb(n + 1, 0);

    for (int i = n - 1; i >= 0; --i) {
      lasta[i] += lasta[i + 1] + (s[i] == 'a');
      lastb[i] += lastb[i + 1] + (s[i] == 'b');
    }

    int ans = 0;
    int as = 0;
    int bs = 0;
    for (int i = 0; i < n; ++i) {
      as += s[i] == 'a';
      bs += s[i] == 'b';
      int bs2 = 0;
      for (int j = i + 1; j < n; ++j) {
        bs2 += s[j] == 'b';
        if (j + 1 < n) {
          ans = max(ans, as + bs2 + lasta[j + 1]);
        }
        ans = max(ans, as + lastb[j]);
        ans = max(ans, bs + lasta[j]);
      }

      ans = max(as, ans);
      ans = max(bs, ans);
    }

    cout << ans << endl;
  }

  return 0;
}