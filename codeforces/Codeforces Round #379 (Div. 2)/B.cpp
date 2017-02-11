// http://codeforces.com/contest/734/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  long long mm = min(a, min(c, d));
  long long sum = mm * 256LL;
  a -= mm;
  c -= mm;
  d -= mm;

  mm = min(a, b);
  sum += mm * 32LL;

  cout << sum << endl;

  return 0;
}