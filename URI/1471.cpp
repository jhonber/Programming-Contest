#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<int> v(n, 0);
    for (int i = 0; i < m; ++i) {
      int a;
      cin >> a;
      v[a - 1] = true;
    }

    int first = false;
    for (int i = 0; i < n; ++i) {
      if (!v[i]) {
        cout << i + 1 << " ";
        first = true;
      }
    }
    if (!first) cout << "*";
    cout << endl;
  }

}
