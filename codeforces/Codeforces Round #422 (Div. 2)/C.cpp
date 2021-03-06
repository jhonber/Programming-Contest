// http://codeforces.com/contest/822/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

const int MAX = 200200;

bool cmp (pair<int, int> i, pair<int, int> j) {
  if (i.first == j.first) return i.second > j.second;
  return i.first < j.first;
}

int main() {
  int n, x;
  while (cin >> n >> x) {
    vector<pair<int, int>> sizes[MAX];
    vector<pair<int, int>> v(n);
    vector<int> cost(n);
    for (int i = 0; i < n; ++i) {
      int l, r, c;
      cin >> l >> r >> c;

      v[i] = {l, r};
      cost[i] = c;
      sizes[r - l + 1].push_back({l, c});
    }

    for (int i = 0; i < MAX; ++i) {
      sort(sizes[i].begin(), sizes[i].end(), cmp);
    }

    for (int i = 0; i < MAX; ++i) {
      int t = sizes[i].size();
      if (t > 0) {
        for (int j = t - 2; j >= 0; --j) {
          sizes[i][j].second = min(sizes[i][j].second, sizes[i][j + 1].second);
        }
      }
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
      int t = x - (v[i].second - v[i].first + 1);
      if (t < 0) continue;

      pair<int, int> r = {v[i].second + 1, 0};

      auto ind = lower_bound(sizes[t].begin(), sizes[t].end(), r);

      if (ind != sizes[t].end()) {
        ans = min(ans, ind->second + cost[i]);
      }
    }
    cout << (ans == INT_MAX ? -1 : ans) << endl;
  }

  return 0;
}