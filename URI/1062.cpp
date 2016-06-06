#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;

    int f = false;
    while (true) {
      vector<int> v(n);
      for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (!v[i]) {
          f = true;
          break;
        }
      }

      if (f) break;

      reverse(v.begin(), v.end());

      vector<int> v2;
      for (int i = 1; i <= n; ++i) {
        v2.push_back(i);
        while (!v2.empty() && !v.empty() && v.back() == v2.back()) {
          v.pop_back();
          v2.pop_back();
        }
      }

      cout << (v.size() > 0 ? "No": "Yes") << endl;
    }

    cout << endl;
  }

  return 0;
}