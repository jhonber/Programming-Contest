#include<bits/stdc++.h>
using namespace std;

long long pot(long long b, long long p, long long m) {
  long long mask = 1;
  long long pow2 = b % m;
  long long r = 1;

  while (mask) {
    if (p & mask) r = (r * pow2) % m;
    pow2 = (pow2 * pow2) % m;
    mask <<= 1;
  }
  return r;
}

int main() {
  long long m = 2147483647;
  long long r;
  cin >> r;

  long long p = (pot(3,r,m) + m) % m;
  cout << p << endl;
  return 0;
}
