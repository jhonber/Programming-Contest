// http://codeforces.com/contest/673/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  vector<int> v(91, 0);
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    v[a] = true;
  }

  int ans = 0;
  int bad = 0;
  for (int i = 1; i <= 90; ++i) {
    bad += !v[i];
    if (v[i]) {
      bad = 0;
    }

    ans ++;
    if (bad == 15) {
      break;
    }
  }

  cout << ans << endl;
  return 0;
}