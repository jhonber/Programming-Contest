#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

bool comp(pair<int, int> i, pair<int, int> j) {
  int diff1 = abs(i.second - i.first);
  int diff2 = abs(j.second - j.first);

  return diff1 < diff2;
}

int main() {
  int n, m;

  while (cin >> n >> m) {
    int a, b;

    int ans = 0;
    vector<pair<int, int>> loss;
    for (int i = 0; i < n; ++i) {
      cin >> a >> b;
      if (a <= b) loss.push_back({a, b});
      else ans += 3;
    }

    sort(loss.begin(), loss.end(), comp);

    for (int i = 0; i < loss.size(); ++i) {
      int diff = (loss[i].second - loss[i].first) + 1;
      if (m - diff >= 0) {
        m -= diff;
        ans += 3;
      }
      else if (m - (diff - 1) >= 0) {
        m -= (diff - 1);
        ans ++;
      }
      else if (loss[i].first == loss[i].second) {
        ans ++;
      }
    }

    cout << ans << endl;
  }

  return 0;
}