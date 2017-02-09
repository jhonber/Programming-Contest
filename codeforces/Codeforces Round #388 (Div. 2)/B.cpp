#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

struct point {
  int x, y;
  point () {}
  point (int a, int b) {
    x = a;
    y = b;
  }

  point operator - (const point &other) const {
    return point(x - other.x, y - other.y);
  }

  point operator + (const point &other) const {
    return point(x + other.x, y + other.y);
  }

  void print () {
    cout << x << " " << y << endl;
  }
};

int main() {
  int x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  point a(x1, y1), b(x2, y2), c(x3, y3);

  cout << 3 << endl;
  point aa = a - b + c;
  point bb = a - c + b;
  point cc = c - a + b;

  aa.print();
  bb.print();
  cc.print();

  return 0;
}
