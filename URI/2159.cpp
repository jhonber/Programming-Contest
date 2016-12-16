#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  cout << fixed << setprecision(1);
  cout << n / log(n) << " " << 1.25506 * n / log(n) << endl;
  return 0;
}