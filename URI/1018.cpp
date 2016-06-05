#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  int v[] = {100, 50, 20, 10, 5, 2, 1};
  cout << n << endl;
  for (int i = 0; i < 7; ++i) {
    printf("%d nota(s) de R$ %d,00\n", n / v[i], v[i]);
    n -= v[i] * (n / v[i]);
  }

  return 0;
}