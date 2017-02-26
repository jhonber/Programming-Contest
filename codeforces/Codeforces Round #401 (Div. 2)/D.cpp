// http://codeforces.com/contest/777/problem/D

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  vector<string> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  for (int i = n - 2; i >= 0; --i) {
    int j = 0, cnt = 0;
    for ( ; v[i][j] && v[i + 1][j]; ++j) {
      if (v[i][j] < v[i + 1][j]) break;
      if (v[i][j] > v[i + 1][j]) v[i][j] = '\0';
      else cnt ++;
    }

    if (cnt == j && v[i][j] && !v[i + 1][j]) v[i][j] = '\0';
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; v[i][j]; ++j) cout << v[i][j];
    cout << endl;
  }

  return 0;
}