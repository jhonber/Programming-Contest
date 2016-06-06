#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

long long ans;

long long f (int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  ans += 2;
  return f(n - 1) + f(n - 2);
}

int main() {
  int n, t;
  cin >> t;
  while (t --> 0) {
    cin >> n;
    ans = 0;
    long long r = f(n);

    cout << "fib(" << n << ") = " << ans << " calls = " << r << endl;
  }

  return 0;
}