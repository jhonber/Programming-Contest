// http://codeforces.com/contest/818/problem/D

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

const int MAX = 1e6 + 10;

int main() {
  int n, a;
  while (cin >> n >> a) {
    vector<int> pos[MAX];

    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      pos[x].push_back(i);
    }

    bool found = false;
    for (int i = 1; i <= MAX; ++i) {
      if (i == a || pos[i].size() == 0) continue;
      bool ok = true;
      for (int j = 0; j < pos[a].size(); ++j) {
        int cnt = lower_bound(pos[i].begin(), pos[i].end(), pos[a][j]) - pos[i].begin();
        if (cnt < j + 1) {
          ok = false;
          break;
        }
      }
      if (ok) {
        cout << i << endl;
        found = true;
        break;
      }
    }

    cout << (found ? "" : "-1") << endl;
  }

  return 0;
}