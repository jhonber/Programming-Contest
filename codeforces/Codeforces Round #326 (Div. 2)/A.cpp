// http://codeforces.com/contest/588/problem/A

#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;


int main() {
  int n,a,p;
  cin >> n;

  int ans = 0;
  int mm = INT_MAX;
  for (int i = 0; i < n; ++i) {
    cin >> a >> p;
    mm = min(mm, p);
    ans += a * mm;
  }

  cout << ans;
  return 0;
}