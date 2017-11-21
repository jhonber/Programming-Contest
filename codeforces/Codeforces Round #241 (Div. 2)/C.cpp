// http://codeforces.com/contest/416/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
#ifdef ONLINEJUDGE
  ios_base::sync_with_stdio(0); cin.tie(0);
#endif

  int n;
  while (cin >> n) {
    vector<int> c(n), p(n);
    for (int i = 0; i < n; ++i) {
      cin >> c[i] >> p[i];
    }

    int k;
    cin >> k;

    vector<pair<int, int>> v(k);
    for (int i = 0; i < k; ++i) {
      cin >> v[i].first;
      v[i].second = i + 1;
    }

    sort(v.begin(), v.end());

    int cnt = 0;
    int ans = 0;
    set<int> ready;
    vector<pair<int, int>> out;
    for (int i = 0; i < k; ++i) {
      int ind = 0;
      int mx = 0;
      for (int j = 0; j < n; ++j) {
        if (ready.count(j) > 0) continue;
        if (v[i].first >= c[j] && mx < p[j]) {
          ind = j;
          mx = p[j];
        }
      }

      if (mx == 0) continue;
      ready.insert(ind);
      out.push_back({ind + 1, v[i].second});
      ans += mx;
      cnt ++;
    }

    cout << cnt << " " << ans << endl;
    for (auto i: out) {
      cout << i.first << " " << i.second << endl;
    }
  }

  return 0;
}