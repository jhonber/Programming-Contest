#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  double a, b, c;
  cin >> a >> b >> c;

  cout << fixed << setprecision(1);

  cout << "MEDIA = " << (a * 2 + b * 3 + c * 5) / 10.0 << endl;

  return 0;
}
