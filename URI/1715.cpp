#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

int main() {
  int n, m;
  cin >> n >> m;

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int cnt = 0;
    for (int j = 0; j < m; ++j) {
      int x;
      cin >> x;
      if (x) cnt ++;
    }

    if (cnt == m) ans ++;
  }

  cout << ans << endl;

  return 0;
}