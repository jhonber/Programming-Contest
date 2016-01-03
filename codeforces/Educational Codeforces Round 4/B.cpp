// http://codeforces.com/contest/612/problem/B

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(NULL); cie.tie(false);
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

  long long ans = 0;
  for (int i = 1; i < n; ++i) {
    ans += abs(v[i].second - v[i - 1].second);
  }

  cout << ans;
  return 0;
}