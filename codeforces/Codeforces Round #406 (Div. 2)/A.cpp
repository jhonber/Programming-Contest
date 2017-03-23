// http://codeforces.com/contest/787/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  set<long long> ready;
  long long i;
  for (i = 1; i < 1e6; ++i) {
    long long x = b + (a * (i - 1));
    ready.insert(x);
  }

  bool ok = false;
  for (i = 1; i < 1e6; ++i) {
    long long y = d + (c * (i - 1));
    if (ready.count(y) > 0) {
      ok = true;
      cout << y << endl;
      break;
    }
  }


  if (!ok) cout << -1 << endl;

  return 0;
}