// http://codeforces.com/contest/596/problem/A

#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;


int main() {
  int n;
  cin >> n;

  vector< pair<int, int> > v(n);
  for (int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (v[i].first != v[j].first && v[i].second != v[j].second) {
        cout << abs(v[i].first - v[j].first) * abs(v[i].second - v[j].second);
        return 0;
      }
    }
  }

  cout << -1;
  return 0;
}