#include<bits/stdc++.h>
using namespace std;

int main() {
  int x,y;
  while (cin >> x >> y) {
    if (x > y) swap(x, y);
    for (int i = x + 1; i < y; ++i) {
      int res = i % 5;
      if (res == 2 || res == 3) cout << i << endl;
    }
  }
}