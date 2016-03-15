#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t;
  cin >> t;
  while (t --> 0) {
    int ax, ay, bx, by, cx, cy, dx, dy, x, y;
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy >> x >> y;

    int yes = false;
    if (x >= ax && x <= bx && y >= ay && y <= dy) yes = true;

    cout << (yes ? 1 : 0) << endl;
  }

  return 0;
}