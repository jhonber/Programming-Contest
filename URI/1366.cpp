#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int a, b;
      cin >> a >> b;
      ans += b / 2;
    }

    cout << ans / 2 << endl;
  }

  return 0;

}