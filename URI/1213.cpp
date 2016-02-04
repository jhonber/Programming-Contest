#include<bits/stdc++.h>
using namespace std;

int mpow(int b, int p, int m) {
  int mask = 1;
  int pow2 = b % m;
  int r = 1;

  while (mask) {
    if (p & mask) r = (r * pow2) % m;
    pow2 = (pow2 * pow2) % m;
    mask <<= 1;
  }

  return r;
}

int solve(long long n) {
  long long x = 1;
  int size = 1;
  for (int i = 1; i < 100000; ++i) {
    x += mpow(10LL, i, n);
    x %= n;
    size ++;
    if (!x) {
      return size;
    }
  }
  assert(false);
}

int main() {
  int n;
  while (cin >> n) {
    cout << solve(n) << endl;
  }

  return 0;
}