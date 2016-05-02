#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int a, b;

  while (cin >> a >> b) {
    if (a > b) swap(a, b);

    int ans = 0;
    for (int i = a; i <= b; ++i) if (i % 13 != 0) {
      ans += i;
    }

    cout << ans << endl;
  }

  return 0;
}