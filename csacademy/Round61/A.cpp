#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
#ifndef ONLINEJUDGE
  ios_base::sync_with_stdio(0); cin.tie(0);
#endif

  double x;
  cin >> x;

  cout << (int)((x * 1.8) + 32) << endl;

  return 0;
}
