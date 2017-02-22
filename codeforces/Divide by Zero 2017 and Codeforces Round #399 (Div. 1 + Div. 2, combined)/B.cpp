// http://codeforces.com/contest/768/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

bool search (long long i, long long l, long long a, long long b, long long p) {
  long long diff = abs(l - i);
  if (diff == 0) return b;
  if (diff == 1) return a;

  p /= 2;

  if (i >= l) {
    i -= p;
  }
  else {
    i += p;
  }

  long long tmp = a;
  a /= 2;
  b = tmp % 2;

  return search(i, l, a, b, p);
}

int main() {
  long long n, l, r;
  cin >> n >> l >> r;

  long long i = 1;
  while (i * 2 < n) i *= 2;
  if (n == 2) i ++;

  int ans = 0;
  while (l <= r) {
    int bit = search(i, l, n / 2, n % 2, i);
    ans += bit;
    l ++;
  }

  cout << ans << endl;
}