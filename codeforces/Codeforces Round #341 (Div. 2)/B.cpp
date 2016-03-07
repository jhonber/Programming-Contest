// http://codeforces.com/contest/621/problem/B

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

int main() {
  int n;
  cin >> n;

  int x, y;
  map<int, int> a, b;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;

    a[x + y] ++;
    b[x - y] ++;
  }

  long long ans = 0;
  for (auto i : a) {
    ans += (i.second * (i.second - 1)) / 2;
  }

  for (auto i : b) {
    ans += (i.second * (i.second - 1)) / 2;
  }

  cout << ans;
  return 0;
}