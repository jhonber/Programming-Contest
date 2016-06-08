// http://codeforces.com/contest/680/problem/A

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  vector<int> v(5);
  for (int i = 0; i < 5; ++i) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  int tot = 0;
  for (int i = 0; i < 5; ++i) {
    tot += v[i];
  }

  int mn = tot;
  if (v[0] == v[1]) {
    mn = min(mn, tot - (v[0] * 2));
  }
  if (v[0] == v[1] && v[1] == v[2]) {
    mn = min(mn, tot - (v[0] * 3));
  }

  if (v[1] == v[2]) {
    mn = min(mn, tot - (v[1] * 2));
  }
  if (v[1] == v[2] && v[2] == v[3]) {
    mn = min(mn, tot - (v[1] * 3));
  }

  if (v[2] == v[3]) {
    mn = min(mn, tot - (v[2] * 2));
  }
  if (v[2] == v[3] && v[3] == v[4]) {
    mn = min(mn, tot - (v[2] * 3));
  }

  if (v[3] == v[4]) {
    mn = min(mn, tot - (v[3] * 2));
  }

  cout << mn << endl;
  return 0;
}