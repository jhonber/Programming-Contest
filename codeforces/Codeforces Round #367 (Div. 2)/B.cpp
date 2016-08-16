// http://codeforces.com/contest/706/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int x;
    cin >> x;

    auto it = upper_bound(v.begin(), v.end(), x);

    if (it != v.begin()) it --;
    else {
      cout << 0 << endl;
      continue;
    }

    int ans = it - v.begin();
    cout << ans + 1 << endl;
  }

  return 0;
}