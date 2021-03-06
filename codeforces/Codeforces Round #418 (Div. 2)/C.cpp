// http://codeforces.com/contest/814/problem/C

#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
#ifdef ONLINE_JUDGE
  IO
#endif

  int n, q;
  while (cin >> n) {
    string s;
    cin >> s >> q;

    while (q --> 0) {
      int a;
      char c;
      cin >> a >> c;

      int t = s.size();
      int ans = 0;
      int i = 0, j = 0;
      int cnt = 0;

      while (i < t && j < t) {
        while (j < t && cnt + (s[j] != c) <= a) {
          cnt += s[j] != c;
          j ++;
        }

        ans = max(ans, j - i);
        cnt -= s[i] != c;

        i ++;
      }

      cout << ans << endl;
    }
  }

  return 0;
}