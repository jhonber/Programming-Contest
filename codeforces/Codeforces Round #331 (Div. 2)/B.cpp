// http://codeforces.com/contest/596/problem/B

#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;


int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  long long acum = 0;
  long long ans = abs(v[0]);
  for (int i = 1; i < n; ++i) {
    ans += abs(v[i] - v[i - 1]);
  }

  cout << ans;
  return 0;
}