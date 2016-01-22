// http://codeforces.com/contest/620/problem/C

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(NULL); cie.tie(false);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  map<int, vector<int> > mapa;
  for (int i = 0; i < n; ++i) {
    mapa[v[i]].push_back(i);
  }

  vector< pair<int, int> > ans;
  int last = 0;
  int ind = n + 1;
  for (int i = 0; i < n; ++i) {
    if (i == ind) {
      ans.push_back({last, i});
      last = i + 1;
      ind = n + 1;
      continue;
    }

    vector<int> :: iterator upp = upper_bound(mapa[v[i]].begin(), mapa[v[i]].end(), i);
    if (upp != mapa[v[i]].end()) {
      if (*upp < ind) {
        ind = *upp;
      }
    }
  }

  if (ans.size() > 0) ans[ans.size() - 1].second = n - 1;

  int len = 0;
  for (int i = 0; i < ans.size(); ++i) {
    len += (ans[i].second - ans[i].first) + 1;
  }

  if (len != n) {
    cout << -1;
    return 0;
  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
  return 0;
}