// http://codeforces.com/contest/135/problem/A

#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  int ind = 0;
  int mx = 0;
  vector< int > v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    if (mx < v[i]) {
      mx = v[i];
      ind = i;
    }
  }

  if (mx == 1) v[ind] = 2;
  else v[ind] = 1;

  sort(v.begin(), v.end());

  for (int i = 0; i < n; ++i) cout << v[i] << " ";

  return 0;
}