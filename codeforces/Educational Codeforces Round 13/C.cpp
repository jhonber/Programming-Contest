// http://codeforces.com/contest/678/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

long long lcm (long long a, long long b) {
  return a / __gcd (a, b) * b;
}

int main() {
  long long n, a, b, p, q;
  cin >> n >> a >> b >> p >> q;

  long long k = n / lcm(a, b);
  if (k > n) k = 0;

  long long ans = ((n / a) - k) * p;
  ans += ((n / b) - k) * q;


  if (p > q) ans += k * p;
  else ans += k * q;

  cout << ans << endl;
  return 0;
}