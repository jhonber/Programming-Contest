// http://codeforces.com/contest/808/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() { IO
  int n, k;

  cout << fixed << setprecision(16);
  while (cin >> n >> k) {
    vector<double> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }

    vector<double> pre(222222);
    pre[0] = 0;
    for (int i = 1; i <= n; ++i) {
      pre[i] = pre[i - 1] + v[i - 1];
    }

    double acum = 0;
    for (int i = 0; i + k <= n; ++i) {
      acum += pre[i + k] - pre[i];
    }

    cout << acum / (n - k + 1) << endl;
  }

  return 0;
}