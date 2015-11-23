// http://codeforces.com/contest/534/problem/B

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define D(x) cout << #x " = " << (x) << endl;

int main() {
  int v1, v2, t, d;
  cin >> v1 >> v2 >> t >> d;
  if (v1 > v2) swap(v1, v2);

  int ans = v1 + v2;
  int ant = v1;
  for (int i = 2; i < t; ++i) {
    int j = ant + d;
    while (j > 0) {
      if (abs(j - ant) <= d && abs((j - (d*((t - i) - 1))) - v2) <= d) break;
      j --;
    }

    if (!j) j = ant + d;

    ans += j;
    ant = j;
  }

  cout << ans;
  return 0;
}