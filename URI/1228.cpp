#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {

    vector<int> v(n), v2(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> v2[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
          if (v2[k] == v[i]) break;
          if (v2[k] == v[j]) ans ++;
        }
      }
    }

    cout << ans << endl;
  }
  return 0;
}