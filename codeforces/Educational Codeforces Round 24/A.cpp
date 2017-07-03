// http://codeforces.com/contest/818/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  long long n, k;
  while (cin >> n >> k) {
    long long y = ceil(n / 2.0);
    long long x = (n - y) / (k + 1);

    cout << x << " " << x * k << " " << n - (x + x * k) << endl;
  }

  return 0;
}