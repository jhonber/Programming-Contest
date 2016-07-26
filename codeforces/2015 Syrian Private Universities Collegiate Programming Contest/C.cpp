#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t;
  cin >> t;

  while (t --> 0) {
    int n;
    cin >> n;

    set<pair<int, int>> cnt;
    for (int it = 0; it < n; ++it) {
      int i, j, k;
      cin >> i >> j >> k;

      for (int a = i; a < j; ++a) {
        for (int b = 0; b < k; ++b) {
          cnt.insert({a, b});
        }
      }
    }

    cout << cnt.size() << endl;
  }

  return 0;
}
