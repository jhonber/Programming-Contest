// http://codeforces.com/contest/805/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  string out;
  for (int i = 0; i < 2 * 1e6; ++i) out += (i & 1 ? "bb" : "aa");
  cout << out.substr(0, n) << endl;

  return 0;
}