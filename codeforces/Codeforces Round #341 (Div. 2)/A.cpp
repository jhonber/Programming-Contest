// http://codeforces.com/contest/621/problem/A

#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  long long ans = 0;
  long long mm = LLONG_MAX;
  int tot = 0;

  long long t;
  for (int i = 0; i < n; ++i) {
    cin >> t;

    ans += t;
    if (t % 2 != 0) {
      tot ++;
      mm = min(mm, t);
    }
  }


  if (tot % 2 != 0) ans -= mm;

  cout << ans;
  return 0;
}