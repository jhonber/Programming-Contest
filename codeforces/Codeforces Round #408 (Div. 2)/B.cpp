// http://codeforces.com/contest/796/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() { IO
  int n, m, k;
  while (cin >> n >> m >> k) {
    unordered_set<int> holes;

    int ans = 1;
    for (int i = 0; i < m; ++i) {
      int x;
      cin >> x;
      holes.insert(x);
    }

    for (int i = 0; i < k; ++i) {
      int a, b;
      cin >> a >> b;

      if (holes.count(ans) > 0) continue;

      if (ans == a) {
        ans = b;
      }
      else if (ans == b) {
        ans = a;
      }
    }

    cout << ans << endl;
  }

  return 0;
}