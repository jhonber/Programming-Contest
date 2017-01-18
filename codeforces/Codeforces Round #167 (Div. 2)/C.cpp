// http://codeforces.com/contest/272/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, m;
  cin >> n;

  vector<long long> mmax(n);
  for (int i = 0; i < n; ++i) cin >> mmax[i];

  for (int i = 1; i < n; ++i)
    mmax[i] = max(mmax[i - 1], mmax[i]);

  long long mx = 0;
  int x, y;
  cin >> m;

  for (int i = 0; i < m; ++i) {
    cin >> x >> y; x --;
    cout << max(mx, mmax[x]) << endl;
    mx = max(mx, mmax[x]);
    mx += y;
  }

  return 0;
}