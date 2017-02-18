// http://codeforces.com/contest/731/problem/F

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int const MX = 200200;

int main() {
  int n;
  cin >> n;

  vector<long long> pre(MX * 2, 0), v(MX, 0);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    pre[x] ++;
    v[x] = 1;
  }

  for (int i = 1; i < MX * 2; ++i) pre[i] += pre[i - 1];

  long long ans = 0;
  for (int i = 0; i < MX; ++i) if (v[i]) {
    long long acum = 0;
    for (int j = i; j < MX; j += i) {
      acum += j * (pre[j + i - 1] - pre[j - 1]);
    }

    ans = max(ans, acum);
  }

  cout << ans << endl;
  return 0;
}