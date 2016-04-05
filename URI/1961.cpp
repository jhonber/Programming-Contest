#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int p, n;

  while (cin >> p >> n) {
    int bef;
    cin >> bef;

    int win = true;
    for (int i = 1; i < n; ++i) {
      int cur;
      cin >> cur;
      if (abs(cur - bef) > p) {
        win = false;
      }

      bef = cur;
    }

    cout << (win ? "YOU WIN": "GAME OVER") << endl;
  }

  return 0;
}
