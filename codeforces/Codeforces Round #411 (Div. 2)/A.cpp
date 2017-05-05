// http://codeforces.com/contest/805/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int l, r;
  cin >> l >> r;

  cout << (l == r ? l : 2) << endl;
  return 0;
}