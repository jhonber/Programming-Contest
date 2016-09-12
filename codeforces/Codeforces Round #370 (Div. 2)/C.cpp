// http://codeforces.com/contest/712/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int x, y;
  cin >> x >> y;

  int v[] = {y, y, y};
  int ans = 0;
  while (true) {
    sort(v, v + 3);
    int num = min(v[2] + v[1] - 1, x);
    v[0] = num;
    ans ++;

    if (v[0] == v[1] && v[1] == v[2]) break;
  }

  cout << ans << endl;
  return 0;
}