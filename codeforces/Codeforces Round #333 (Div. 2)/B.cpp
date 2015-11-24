// http://codeforces.com/contest/602/problem/B

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(NULL); cin.tie(false);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;


int main () {
  int n;
  cin >> n;

  map<int, vector<int> > mapa;

  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    mapa[t].push_back(i);
  }

  for (auto i : mapa) {
    sort(i.second.begin(), i.second.end());
  }

  int mx = 100000;
  int ans = 0;
  for (int i = 2; i <= mx; ++i) {
    vector<int> a = mapa[i - 1];
    vector<int> b = mapa[i];

    for (int x = 0; x < b.size(); ++x) a.push_back(b[x]);
    sort(a.begin(), a.end());

    int f = true;
    int ii = 0;
    for (int j = 1; j < a.size(); ++j) {
      if (a[j - 1] + 1 != a[j]) {
        ans = max(ans, j - ii);
        ii = j;
        f = false;
      }
    }

    if (f) ans = max(ans, (int)a.size());
    ans = max(ans, (int)a.size() - ii);
  }

  cout << ans;

  return 0;
}