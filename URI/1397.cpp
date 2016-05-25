#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;

    int aa, bb;
    aa = bb = 0;
    for (int i = 0; i < n; ++i) {
      int a, b;
      cin >> a >> b;

      if (a == b) continue;
      if (a > b) aa ++;
      else bb ++;
    }

    cout << aa << " " << bb << endl;
  }

  return 0;
}