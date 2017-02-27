// http://codeforces.com/contest/779/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  vector<int> a(n), b(n), c(5 + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    c[a[i]] ++;
  }

  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    c[b[i]] ++;
  }

  bool ok = true;
  int ans = 0;
  for (int i = 0; i < 5; ++i) {
    int tot = 0;
    int cur = i + 1;
    for (int j = 0; j < n; ++j) {
      if (a[j] == cur) tot ++;
    }

    if (c[cur] % 2 != 0) ok = false;
    int mid = c[cur] / 2;
    ans += abs(mid - tot);
  }

  ans /= 2;
  cout << (!ok ? -1 : ans) << endl;
  return 0;
}