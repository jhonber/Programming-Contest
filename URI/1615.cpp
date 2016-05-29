#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t;
  cin >> t;

  while (t --> 0) {
    int n, m;
    cin >> n >> m;

    int mx = 0;
    vector<int> v(n, 0);
    for (int i = 0; i < m; ++i) {
      int a;
      cin >> a;

      v[a - 1] ++;
    }

    int found = false;
    for (int i = 0; i < n; ++i) {
      if (v[i] > m / 2) {
        cout << i + 1 << endl;
        found = true;
        break;
      }
    }

    if (!found) cout << -1 << endl;
  }

  return 0;
}