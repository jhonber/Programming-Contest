#include<bits/stdc++.h>
using namespace std;

string check(int x, int y, int x2, int y2) {
  if (x == x2 || y == y2) return "divisa";
  if (x2 > x && y2 > y) return "NE";
  if (x2 > x && y2 < y) return "SE";
  if (x2 < x && y2 > y) return "NO";
  if (x2 < x && y2 < y) return "SO";
}

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;

    int x, y;
    cin >> x >> y;

    for (int i = 0; i < n; ++i) {
      int x2, y2;
      cin >> x2 >> y2;

      cout << check(x, y, x2, y2) << endl;
    }
  }
}