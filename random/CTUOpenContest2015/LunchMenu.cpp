#include <bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << x << endl;

int main() {
  vector<int> lim(4);
  long long l;
  while (cin >> l >> lim[0] >> lim[1] >> lim[2] >> lim[3]) {
    if (!l) break;

    vector<int> v[4];
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < lim[i]; ++j) {
        int a;
        cin >> a;
        v[i].push_back(a);
      }
    }

    map<int, int> mp1, mp2;
    for (int i = 0; i < v[0].size(); ++i) {
      for (int j = 0; j < v[1].size(); ++j) {
        mp1[v[0][i] + v[1][j]] ++;
      }
    }

    for (int i = 0; i < v[2].size(); ++i) {
      for (int j = 0; j < v[3].size(); ++j) {
        mp2[v[2][i] + v[3][j]] ++;
      }
    }

    int p = 1;
    unordered_map<int, int> pos;
    for (auto i: mp2) {
      pos[i.first] = p ++;
    }

    vector<long long> pre(5050);
    pre[0] = 0;
    int j = 1;
    for (auto i: mp2) {
      pre[j] = pre[j - 1] + i.second;
      j ++;
    }

    long long ans = 0;
    map<int, int> :: iterator it;
    for (auto i: mp1) {
      int x = l - i.first;
      it = mp2.lower_bound(x);
      if (it == mp2.end() || it->first > x) {
        if (it == mp2.begin()) continue;
        it --;
      }

      if (it->first <= x) {
        int n = it->first;
        int ind = pos[n];
        ans += i.second * pre[ind];
      }
    }

    cout << ans << endl;
  }
}
