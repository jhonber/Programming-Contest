// http://codeforces.com/contest/300/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

long long mpow (long long b, long long e, long long mod) {
  long long p = 1;
  while (e > 0) {
    if ((e & 1) != 0)
      p = (p * b) % mod;

    e >>= 1;
    b = (b * b) % mod;
  }

  return p % mod;
}

bool good (int x, int a, int b) {
  while (x) {
    int c = x % 10;
    if (c != a && c != b) return false;
    x /= 10;
  }
  return true;
}

long long count (long long a, long long b, long long mod, vector<long long> fact) {
  long long num = fact[a + b];
  long long den = fact[a] * fact[b];
  den %= mod;

  return (num * mpow(den, mod - 2, mod)) % mod;
}

int main() {
  long long a, b, n;
  cin >> a >> b >> n;

  int lim = 1000010;
  long long mod = 1e9 + 7;
  vector<long long> fact(lim);
  fact[0] = 1;
  for (int i = 1; i < lim; ++i) fact[i] = (fact[i - 1] * i) % mod;

  long long ans = 0;
  for (int i = 0; i <= n; ++i) {
    long long x = a * i + b * (n - i);
    if (good(x, a, b)) {
      ans += count(i, n - i, mod, fact);
      ans %= mod;
    }
  }

  cout << ans << endl;
  return 0;
}