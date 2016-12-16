#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x << " = " << (x) << endl;

double f (int i) {
  if (i == 0) return 2;
  double ans = 0;
  ans += 2 + 1 / f(i - 1);

  return ans;
}

int main() {
  int n;
  cin >> n;

  cout << fixed << setprecision(10);

  if (!n) cout << 1.0 << endl;
  else cout << 1 + f(n) - 2 << endl;
  return 0;
}