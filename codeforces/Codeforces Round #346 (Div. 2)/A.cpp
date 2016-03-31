// http://codeforces.com/contest/659/problem/A

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  vector<int> v(n);
  for (int i = 1; i <= n; ++i) v[i - 1] = i;

  int inc = 1;
  if (b < 0) inc = -1;

  int i, j;
  for (i = a - 1, j = 0; j < abs(b); ++j) {
    i += inc;
    if (i < 0) i = n - 1;
  }

  cout << v[i % n] << endl;
  return 0;
}