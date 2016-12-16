#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x << " = " << (x) << endl;

double f (int i) {
  if (i == 0) return 6.0;

  double ans = 0;
  ans = 6 + (1 / f (i - 1));
  return ans;
}

int main() {
  int n;
  cin >> n;

  cout << fixed << setprecision(10);

  if (!n) cout << 3.0 << endl;
  else cout << (3 + f(n) - 6) << endl;

  return 0;
}