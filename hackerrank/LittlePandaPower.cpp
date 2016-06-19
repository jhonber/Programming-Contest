// https://www.hackerrank.com/contests/infinitum8/challenges/littlepandapower

#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

// return (a^b) % c
long long mod_pow(long long b, long long p, long long m) {
  long long mask = 1LL;
  long long pow2 = b % m;
  long long r = 1LL;
  while (mask) {
    if (p & mask) r = (r * pow2) % m;
    pow2 = (pow2 * pow2) % m;
    mask <<= 1;
  }
  return r;
}

long long extended_euclid (long long a, long long b, long long &x, long long &y) {
  long long xx = y = 0;
  long long yy = x = 1;
  while (b) {
    long long q = a / b;
    long long t = b;
    b = a % b;
    a = t;
    t = xx;
    xx = x - q * xx;
    x = t;
    t = yy;
    yy = y - q * yy;
    y = t;
  }
  return a;
}

long long mod (long long a, long long b) {
  return ((a % b) + b) % b;
}

long long mod_inverse (long long a, long long n) {
  long long x, y;
  long long d = extended_euclid (a, n, x, y);
  if (d > 1)
    return -1;
  return mod (x, n);
}

int main() {
  long long tc,A,B,X;
  cin >> tc;
  while (tc --> 0) {
    cin >> A >> B >> X;
    long long ans = 1;
    if (B < 0) {
      B *= -1LL;
      long long inv = mod_inverse(A,X) % X;
      ans = mod_pow(inv, B, X);
    }
    else if (B > 0) {
      ans = mod_pow(A, B, X);
    }

    cout << ans % X << endl;
  }
  return 0;
}
