// http://codeforces.com/contest/703/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, k;
  cin >> n >> k;

  long long tot = 0;
  vector<long long> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    tot += v[i];
  }

  vector<int> cap(n);
  for (int i = 0; i < k; ++i) {
    int a;
    cin >> a; a --;
    cap[a] = true;
  }

  long long ans = 0;
  set<pair<int, int>> ready;
  for (int i = 0; i < n; ++i) {
    if (cap[i]) {
      ans += v[i] * (tot - v[i]);
      tot -= v[i];
    }
    else {
      int left = i - 1;
      int right = i + 1;

      if (left < 0) left = n - 1;
      if (right == n) right = 0;

      pair<int, int> l = {min(i, left), max(i, left)};
      pair<int, int> r = {min(i, right), max(i, right)};

      if (!cap[left] && ready.count(l) == 0) {
        ans += v[i] * v[left];
        ready.insert(l);
      }

      if (!cap[right] && ready.count(r) == 0) {
        ans += v[i] * v[right];
        ready.insert(r);
      }
    }
  }

  cout << ans << endl;

  return 0;
}