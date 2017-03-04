// http://codeforces.com/contest/448/problem/D

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

bool f (long long mid, long long n, long long m, long long k) {
  long long sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum += min(mid / i, m);
    if (sum >= k) return false;
  }

  return true;
}

int main() {
  long long n, m, k;
  cin >> n >> m >> k;

  long long lo, hi, mid;
  lo = 1;
  hi = (n * m) * 2;

  while (lo < hi) {
    mid = (lo + hi) / 2;
    if (f(mid, n, m, k)) {
      lo = mid + 1;
    }
    else {
      hi = mid;
    }
  }

  cout << lo << endl;

  return 0;
}