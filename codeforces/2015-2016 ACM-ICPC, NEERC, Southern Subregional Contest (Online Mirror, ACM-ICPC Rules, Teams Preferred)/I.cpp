// http://codeforces.com/contest/589/problem/I

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define D(x) cout << #x " = " << (x) << endl;


int main () {
  int n, k;
  cin >> n >> k;

  vector<int> v(k + 1, 0);
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    v[t] ++;
  }

  int x = n / k;
  int ans = 0;

  for (int i = 1; i <= k; ++i) {
    if (v[i] > x)
      ans += v[i] - x;
  }

  cout << ans;
  return 0;
}