#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int a, b;
  while (cin >> a >> b) {
    if (a + b == 0) break;

    vector<int> v(a);
    for (int i = 0; i < a; ++i) cin >> v[i];

    for (int i = 0; i < b; ++i) {
      int x, y, val;
      cin >> x >> y >> val; x --; y --;

      v[x] -= val;
      v[y] += val;
    }

    int paila = false;
    for (int i = 0; i < a; ++i) if (v[i] < 0) {
      paila = true;
      break;
    }

    cout << (paila ? "N" :"S") << endl;
  }

  return 0;
}