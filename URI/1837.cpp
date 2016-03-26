#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " == " << (x) << endl;

int main() {
  int a, b;
  cin >> a >> b;

  if (a < 0) {
    int q = ceil(abs((double)a / b));
    if (b > 0) q *= -1;
    int r = a - (q * b);
    cout << q << " " << r << endl;
  }
  else {
    int q, r;
    q = a / b;
    r = a % b;
    cout << q << " " << r << endl;
  }

  return 0;
}