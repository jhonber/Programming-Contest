#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

bool get_color (int x, int y) {
  return x % 2 == y % 2;
}

int main() {
  int t;
  cin >> t;

  int n;
  cin >> n;

  while (t --> 0) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;


    if (get_color(a, b) == get_color(c, d)) cout << max(abs(a - c), abs(b - d)) << endl;
    else cout << "can't reach!" << endl;
  }

  return 0;
}
