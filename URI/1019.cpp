#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;

  while (cin >> n) {
    int h, m;
    h = n / 3600;
    n -= (n / 3600) * 3600;

    m = n / 60;
    n -= (n / 60) * 60;

    cout << h << ":" << m << ":" << n << endl;
  }

  return 0;
}