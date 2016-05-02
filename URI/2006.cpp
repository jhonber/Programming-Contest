#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t;
  cin >> t;

  int ans = 0;
  for (int j = 0; j < 5; ++j) {
    int a;
    cin >> a;
    if (t == a) ans ++;
  }

  cout << ans << endl;

  return 0;
}