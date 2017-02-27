// http://codeforces.com/contest/779/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string n;
  int k;

  cin >> n >> k;

  int i;
  int ans = 0;
  int tot = 0;
  for (i = n.size() - 1; i >= 0; --i) {
    if (n[i] == '0') tot ++;
    else ans ++;
    if (tot == k) break;
  }

  if (tot < k) {
    ans = n.size() - 1;
  }

  cout << ans << endl;
}