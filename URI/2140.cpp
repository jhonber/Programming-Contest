#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int v[] = {2, 5, 10, 20, 50, 100};

  int a, b;
  while (cin >> a >> b) {
    if (a + b == 0) break;
    int diff = b - a;

    string ans = "impossible";
    int f = false;
    for (int i = 0; i < 6 && !f; ++i) {
      for (int j = i + 1; j < 6 && !f; ++j) {
        if (v[i] + v[j] == diff) {
          ans = "possible";
          f = true;
        }
      }
    }

    cout << ans << endl;
  }

  return 0;
}