#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  double a, b, diff;
  cin >> a >> b;

  diff = b - a;
  printf("%.02lf%\n", (diff * 100.0) / a);
  return 0;
}