// http://codeforces.com/contest/779/problem/D

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL)

bool good (string &a, string &b, vector<int> &p, int x) {
  if (x < b.size()) return false;

  vector<int> pos(x);
  for (int i = 0; i < x; ++i) pos[i] = p[i];
  sort(pos.begin(), pos.end());

  int i = 0, j = 0, len = 0;
  while (i < b.size() && j < x) {
    if (b[i] == a[pos[j]]) {
      len ++;
      i ++;
      j ++;
    }
    else {
      while (j < x && a[pos[j]] != b[i]) j ++;
    }
  }

  return len == b.size();
}

int main() {
#ifdef ONLINE_JUDE
  IO
#endif

  string a, b;
  cin >> a >> b;

  if (a == b) {
    cout << 0 << endl;
    return 0;
  }

  int n = a.size();
  vector<int> v(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    v[i] --;
  }

  reverse(v.begin(), v.end());

  int mid;
  int lo = 0;
  int hi = n;

  while (lo < hi) {
    mid = (lo + hi) / 2;

    if (good(a, b, v, mid)) {
      hi = mid;
    }
    else {
      lo = mid + 1;
    }
  }

  cout << n - hi << endl;

  return 0;
}