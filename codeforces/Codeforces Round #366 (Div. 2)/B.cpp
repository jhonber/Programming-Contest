// http://codeforces.com/contest/705/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  vector<long long> pre(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    long long x;
    cin >> x;

    pre[i + 1] = pre[i] + (x - 1);
  }

  for (int i = 1; i <= n; ++i) {
    if (pre[i] % 2 == 0) cout << 2 << endl;
    else cout << 1 << endl;
  }

  return 0;
}