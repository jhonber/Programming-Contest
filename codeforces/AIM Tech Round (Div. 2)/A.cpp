// http://codeforces.com/contest/624/problem/A

#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  double d, l, v1, v2;
  cin >> d >> l >> v1 >> v2;

  cout << fixed << setprecision(15) << (l - d) / (v1 + v2);
  return 0;
}