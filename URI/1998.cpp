#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

int main() {
  int n;
  while (cin >> n) {
    if (n == -1) break;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    while (true) {
      int found = false;
      int i = 0;
      for (; i < n; ++i) {
        if (v[i] == i + 1) {
          found = true;
          break;
        }
      }

      if (!found) break;
      for (int j = 0; j < i && v[i] > 0; ++j) {
        v[j] ++;
        v[i] --;
      }
      v[i] = 0;
    }

    int tot = accumulate(v.begin(), v.end(), 0);
    cout << (!tot ? "S" : "N") << endl;
  }

  return 0;
}