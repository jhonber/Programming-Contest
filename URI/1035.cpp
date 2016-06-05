#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int f = false;
  if (b > c && d > a && c + d > a + b && c > 0 && d > 0 && a % 2 == 0)
    f = true;

  if (f) cout << "Valores aceitos" << endl;
  else cout << "Valores nao aceitos" << endl;

  return 0;
}