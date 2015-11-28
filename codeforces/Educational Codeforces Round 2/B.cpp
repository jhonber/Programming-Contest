// http://codeforces.com/contest/600/problem/B

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);

int main () {
  int n, m;
  cin >> n >> m;

  vector<int> a(n), b(m);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < m; ++i) cin >> b[i];

  sort(a.begin(), a.end());

  for (int i = 0; i < m; ++i) {
    int cur = b[i];
    int ind = (upper_bound(a.begin(), a.end(), cur)) - a.begin();
    cout << ind << " ";
  }

  return 0;
}