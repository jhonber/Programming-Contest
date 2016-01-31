#include<bits/stdc++.h>
using namespace std;

int main() {
  double ans = 1;

  for (int i = 2; i < 101; ++i) {
    ans += 1.0/ i;
  }

  cout << ans << endl;

  return 0;
}
