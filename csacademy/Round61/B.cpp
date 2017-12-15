#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
#ifndef ONLINEJUDGE
  ios_base::sync_with_stdio(0); cin.tie(0);
#endif

  int n;
  cin >> n;

  n *= 2;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  int a = 0;
  bool cur = 0;
  for (int i = 0; i < n; ++i) {
    if (v[i] != cur) a ++;
    cur = !cur;
  }


  a /= 2;
  int b = 0;
  cur = 1;
  for (int i = 0; i < n; ++i) {
    if (v[i] != cur) b ++;
    cur = !cur;
  }

  b /= 2;
  cout << min(a, b) << endl;
  return 0;
}
