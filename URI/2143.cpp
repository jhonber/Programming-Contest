#include<bits/stdc++.h>
using namespace std;
#define d(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;
    while (n --> 0) {
      int a;
      cin >> a;
      if (a % 2 == 0)
        cout << (a * 2) - 2 << endl;
      else
        cout << (a * 2) - 1 << endl;
    }
  }

  return 0;
}