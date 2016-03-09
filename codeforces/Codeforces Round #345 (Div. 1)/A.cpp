// http://codeforces.com/contest/650/problem/A

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  map <int, long long> xx, yy;
  map < pair<int, int>, long long> rep;

  int x, y;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    xx[x] ++;
    yy[y] ++;
    rep[{x, y}] ++;
  }

  long long ans = 0;
  for (auto i : xx) {
    ans += (i.second * (i.second - 1)) / 2;
  }

  for (auto i : yy) {
    ans += (i.second * (i.second - 1)) / 2;
  }

  for (auto i : rep) {
    ans -= (i.second * (i.second - 1)) / 2;
  }

  cout << ans;
  return 0;
}