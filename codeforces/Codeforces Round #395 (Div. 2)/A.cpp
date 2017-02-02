// http://codeforces.com/contest/764/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, m, z;
  cin >> n >> m >> z;

  vector<int> v(z + 1, 0);
  for (int i = m; i <= z; i += m) {
    v[i] = 1;
  }


  int ans = 0;
  for (int i = n; i <= z; i += n) {
    if (v[i]) ans ++;
  }

  cout << ans << endl;
  return 0;
}