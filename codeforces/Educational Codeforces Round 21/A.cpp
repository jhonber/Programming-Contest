// http://codeforces.com/contest/808/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

long long size (long long n) {
  long long s = 1;
  while (n > 0) {
    n /= 10;
    s *= 10;
  }

  return s / 10;
}

int main() {
  long long n;
  while (cin >> n) {
    long long t = size (n);
    long long q = (1 + (n / t)) * t;
    cout << q - n << endl;
  }

  return 0;
}