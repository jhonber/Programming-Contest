// http://codeforces.com/contest/606/problem/C

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  vector< pair<int, int> > v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first;
    v[i].second = i;
  }

  sort(v.begin(), v.end());

  vector<int> pre(111111, 0);
  pre[0] = 1;

  for (int i = 1; i < n; ++i) {
    if (v[i].second > v[i - 1].second) pre[i] = pre[i - 1] + 1;
    else pre[i] = 1;
  }


  int mx = *max_element(pre.begin(), pre.end());
  int ans = n - mx;

  cout << ans;
  return 0;
}