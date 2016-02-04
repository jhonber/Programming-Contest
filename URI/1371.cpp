#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;

    cout << 1;
    int x = 1;
    for (int i = 3; ; i += 2) {
      x += i;
      if (x > n) break;
      cout << " " << x;
    }

    cout << endl;
  }

  return 0;
}