#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int x, z;
  cin >> x;

  while (cin >> z) {
    if (z > x) break;
  }

  int ans = 0;
  int sum = 0;
  while (sum <= z) {
    ans ++;
    sum += x;
    x ++;
  }

  cout << ans << endl;
  return 0;
}