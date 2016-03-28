#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    int mx = 0;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      mx = max(mx, a);
    }

    if (mx < 10) cout << 1 << endl;
    else if (mx >= 10 && mx < 20) cout << 2 << endl;
    else cout << 3 <<endl;
  }

  return 0;
}
