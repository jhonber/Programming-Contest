// http://codeforces.com/contest/707/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

bool check(long long a, long long b, long long c) {
  if (a * a + b * b == c * c) return true;
  if (b * b + c * c == a * a) return true;
  if (c * c + a * a == b * b) return true;
  return false;
}

int main() {
  long long x;
  cin >> x;

  if (x < 3) {
    cout << -1 << endl;
    return 0;
  }

  if (x % 2 == 0) {
    long long m = x / 2;
    long long n = 1;

    long long a = m * m - n * n;
    long long b = x;
    long long c = m * m + n * n;

    if (check(a, b, c)) {
      cout << a << " " << c << endl;
    }
    else cout << -1 << endl;
  }
  else {
    long long m = (x - 1) / 2;
    long long n = (x + 1) / 2;

    long long a = x;
    long long b = 2 * m * n;
    long long c = m * m + n * n;

    if (check(a, b, c)) {
      cout << b << " " << c << endl;
    }
    else cout << -1 << endl;
  }

  return 0;
}