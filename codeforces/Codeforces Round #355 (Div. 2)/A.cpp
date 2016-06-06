// http://codeforces.com/contest/677/problem/A

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, h;
  cin >> n >> h;

  int ans = n;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;

    if (a > h) ans ++;
  }

  cout << ans << endl;

  return 0;
}