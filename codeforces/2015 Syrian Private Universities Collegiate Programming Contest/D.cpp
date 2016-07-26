#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios::sync_with_stdio(false); cin.tie(NULL);

int main() { IO
  int t;
  cin >> t;

  while (t --> 0) {
    int n;
    cin >> n;

    vector<int> v(n);
    set<int> pos[22222];
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      pos[v[i]].insert(i);
    }

    int best = 0;
    for (int i = 0; i < n; ++i) {
      int next = v[i] + 1;
      int len = 1;
      int ind = i;
      while (true) {
        if (pos[next].size() == 0) break;
        auto it = pos[next].lower_bound(ind);
        if (it != pos[next].end()) {
          next ++;
          ind = *it;
        }
        else break;
        len ++;
      }

      best = max(best, len);
    }

    cout << best << endl;
  }

  return 0;
}
