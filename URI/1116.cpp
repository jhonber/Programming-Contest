#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  while (n --> 0) {
    double a, b;
    cin >> a >> b;

    if (b == 0.0) {
      cout << "divisao impossivel" << endl;
    }
    else printf("%.1lf\n", a / b);
  }

  return 0;
}