// http://codeforces.com/contest/782/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  int ans = 0;
  set<int> table;

  for (int i = 0; i < 2 * n; ++i) {
    int x;
    cin >> x;

    ans = max(ans, (int)table.size());
    if (table.count(x) > 0) {
      table.erase(x);
    }
    else {
      table.insert(x);
    }
    ans = max(ans, (int)table.size());
  }

  cout << ans << endl;

  return 0;
}