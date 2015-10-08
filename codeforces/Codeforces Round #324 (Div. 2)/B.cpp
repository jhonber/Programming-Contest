// http://codeforces.com/contest/584/problem/B

#include<bits/stdc++.h>
using namespace std;

long long md = 1e9 + 7;

long long mpow (long long a, long long b) {
  long long p = a;
  while (b --> 1) {
    p = (p * a) % md;
    p %= md;
  }

  return p % md;
}

int main() {
  int n;
  cin >> n;

  long long a = mpow(3LL, n * 3);
  long long b = mpow(7LL, n);
  long long tmp = (a + md) - b;
  cout << tmp % md;
}