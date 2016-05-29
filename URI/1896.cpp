#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

struct car {
  int x, y, z;
  car () {
    x = y = z = 0;
  }
  car (int _x, int _y, int _z): x(_x), y(_y), z(_z) {};

  bool operator == (const car & j) const {
    return x == j.x && y == j.y && z == j.z;
  }

  void print() {
    cout << x << " " << y << " " << z << endl;
  }
};

int main() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;

  car target(a, b, c);

  vector<car> v(n);
  for (int i = 0; i < n; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    car c(x, y, z);

    v[i] = c;
  }

  int lim = 1 << n;
  int mask = 0;
  int found = false;

  while (mask < lim && !found) {
    int ones = __builtin_popcount(mask);
    if (ones > 1) {
      int p = 1;
      int ind = n - 1;
      car r;
      while (p <= mask && !found) {
        if (p & mask) {
          r.x += v[ind].x;
          r.y += v[ind].y;
          r.z += v[ind].z;

          if (r == target) {
            found = true;
          }
        }

        p *= 2;
        ind --;
      }
    }

    mask ++;
  }

  cout << (found ? 'Y' : 'N') << endl;

  return 0;
}