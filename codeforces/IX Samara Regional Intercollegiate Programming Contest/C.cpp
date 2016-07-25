// http://codeforces.com/problemset/gymProblem/100971/C

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  sort(v.begin(), v.end());

  int paila = false;
  int diff = (v.back() - v[0]) + 1;
  if (v[0] + v[1] <= diff) paila = true;

  if (!paila) {
    cout << "YES" << endl << diff << endl;
  }
  else {
    cout << "NO" << endl;
  }

  return 0;
}
