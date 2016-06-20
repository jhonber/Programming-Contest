#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

int main() {
  int t;
  while (cin >> t) {
    if (!t) break;

    for (int i = 0; i < t; ++i) {
      double tot, a, b;
      cin >> tot >> a >> b;

      double area = ((a * 5) / 2) + ((b * 5) / 2);
      area *= tot;

      cout << "Size #" << i + 1 << ":" << endl;
      cout << fixed << setprecision(2);
      cout << "Ice Cream Used: " << area << " cm2" << endl;
    }

    cout << endl;
  }

  return 0;
}