// http://codeforces.com/contest/622/problem/A

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);

long long f (long long x) {
  long long x1 = ceil((-1LL + sqrt(1LL + 8LL * x)) / 2.0);
  long long x2 = ceil((-1LL - sqrt(1LL + 8LL * x)) / 2.0);
  return max(x1, x2);
}

long long sum (long long n) {
  return (n * (n + 1)) / 2;
}

int main () {
  long long x;
  while (cin >> x) {
    long long n = f(x);
    x -= sum(n - 1);
    cout << x << endl;
  }

  return 0;
}