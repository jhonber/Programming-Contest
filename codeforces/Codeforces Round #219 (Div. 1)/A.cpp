// http://codeforces.com/contest/372/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  sort(v.begin(), v.end());
  int ans = n;

  int i = 0;
  int j = n / 2;
  while (i < n / 2 && j < n) {
    if (v[i] * 2 <= v[j]) {
      i ++;
      j ++;
      ans --;
    }
    else {
      j ++;
    }
  }

  cout << ans << endl;

  return 0;
}