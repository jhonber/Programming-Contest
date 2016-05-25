#include<bits/stdc++.h>
using namespace std;

#define D(x) //cout << #x << " = " << (x) << endl;

int main() {
  int n, m;
  while (cin >> n >> m) {
    if (n + m == 0) break;

    int ind = 0;
    int level = 0;
    vector<int> G[m];
    for (int i = 0; i < m; ++i) {
      int a;
      cin >> a;
      for (int j = 0; j < a; ++j) {
        int ai;
        cin >> ai;

        G[i].push_back(ai);
        if (ai == 1) {
          ind = i;
          level = j;
        }
      }
    }

    int self = G[ind].size() - (level + 1);

    int cnt1 = 0;
    for (int j = ind - 1; j >= 0; --j) {
      if (level + 1 > G[j].size()) break;
      int cnt = G[j].size() - (level );
      if (cnt > 0) cnt1 += cnt;
    }

    int cnt2 = 0;
    for (int j = ind + 1; j < m; ++j) {
      if (level + 1 > G[j].size()) break;
      int cnt = G[j].size() - (level );
      if (cnt > 0) cnt2 += cnt;
    }

    D(cnt1) D(cnt2)
    cout << min(cnt1, cnt2) + self << endl;

  }

  return 0;
}