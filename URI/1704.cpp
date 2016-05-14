#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

int main() { IO
  int n, h;
  while (cin >> n >> h) {
    int val, t;

    int tot = 0;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> val >> t;
      v[i] = {val, t};
      tot += val;
    }

    sort(v.begin(), v.end());

    int earns = 0;
    vector<int> ready(h + 1, 0);

    for (int i = n - 1; i >= 0; --i) {
      for (int j = v[i].second; j > 0; --j) {
        if (!ready[j]) {
          ready[j] = true;
          earns += v[i].first;
          break;
        }
      }
    }

    cout << tot - earns << endl;
  }

  return 0;
}