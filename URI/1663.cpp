#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;
    vector<int> v(n), vv(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    for (int i = 0; i < n; ++i) {
      vv[v[i] - 1] = i + 1;
    }

    int eq = 0;
    int f = false;
    for (int i = 0; i < n; ++i) {
      if (v[i] == vv[i]) {
        eq ++;
      }
    }

    if (eq == n) cout << "ambiguous" << endl;
    else cout << "not ambiguous" << endl;
  }

  return 0;
}
