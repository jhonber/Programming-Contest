#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, m;
  while (cin >> n >> m) {
    if (!n) break;

    map<int, int> score;
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < m; ++k) {
        int a;
        cin >> a;
        score[a] ++;
      }
    }

    set<int> v;
    for (auto i : score) {
      v.insert(i.second);
    }

    set<int> :: iterator it = v.end();
    it --; it--;

    int second = *it;
    vector<int> ans;

    for (auto i : score) {
      if (i.second == second) {
        ans.push_back(i.first);
      }
    }

    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
    cout << endl;
  }

  return 0;
}
