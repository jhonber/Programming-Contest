// http://codeforces.com/contest/764/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  int a = 0;
  int b = n - 1;

  int cnt = 0;
  while (a <= b) {
    if (cnt % 2 == 0)
      swap(v[a], v[b]);

    a ++;
    b --;
    cnt ++;
  }

  for (int i = 0; i < n; ++i) cout << v[i] << " "; cout << endl;

  return 0;
}