// http://codeforces.com/contest/892/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() { IO;
  int n;
  while (cin >> n) {
    vector<int> v(n);
    vector<int> mm(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    mm[n - 1] = (n - 1) - v[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      mm[i] = min(mm[i + 1], i - v[i]);
    }

    int ans = n;
    for (int i = 1; i < n; ++i) {
      if (i - 1 >= mm[i]) ans --;
    }

    cout << ans << endl;
  }

  return 0;
}