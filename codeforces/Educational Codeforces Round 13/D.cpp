// http://codeforces.com/contest/678/problem/D

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

const long long m = 1e9 + 7;

long long mod_pow(long long b, long long e) {
  long long p = 1;
  while (e > 0) {
    if ((e & 1) != 0)
      p = (p * b) % m;

    e >>= 1;
    b = (b * b) % m;
  }

  return p % m;
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
  long long a, b, n, x;
  cin >> a >> b >> n >> x;

  if (a == 1) {
    cout << (x + b * (n % m)) % m << endl;
    return 0;
  }

  long long p = (mod_pow(a, n) * x) % m;
  long long q = (mod_pow(a, n) + m - 1) % m;
  q = (q * mod_inverse(a - 1, m)) % m;

  cout << (p + q * b) % m << endl;
  return 0;
}