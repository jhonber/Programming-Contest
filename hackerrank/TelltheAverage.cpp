// https://www.hackerrank.com/contests/infinitum8/challenges/tell-the-average

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int solve (vector<long long> &v) {
  int i = 1;
  while (i < v.size()) {
    v[0] = v[0] % MOD + v[i] % MOD + (v[0] % MOD * v[i] % MOD) % MOD;
    i ++;
  }
  return v[0] % MOD;
}

int main() {
  int n;
  cin >> n;

  vector<long long> v(n);
  for (int i = 0; i < n; ++i)
    cin >>v[i];

  cout << solve(v);
  return 0;
}
