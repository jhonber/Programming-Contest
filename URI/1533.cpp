#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;
    vector< pair<int, int> > v(n);
    for (int i = 0; i < n; ++i) {
      int t;
      cin >> t;
      v[i] = {t, i + 1};
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    cout << v[1].second << endl;
  }

  return 0;
}