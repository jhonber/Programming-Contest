#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int x, y;
  vector<string> ans = {"primeiro", "segundo", "terceiro", "quarto"};

  while (cin >> x >> y) {
    if (!x || !y) break;
    if (x > 0 && y > 0) cout << ans[0];
    else if (x < 0 && y > 0) cout << ans[1];
    else if (x < 0 && y < 0) cout << ans[2];
    else cout << ans[3];
    cout << endl;
  }

  return 0;
}