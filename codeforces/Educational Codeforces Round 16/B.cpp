// http://codeforces.com/contest/710/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  sort(v.begin(), v.end());
  cout << v[(n - 1) / 2] << endl;
  return 0;
}