#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  long long a, b;
  while (cin >> a >> b) {
    if (!a && !b) break;
    long long x1 = (a * 3) - (a + b);
    long long x2 = (b * 3) - (a + b);

    cout << min(x1, x2) << endl;
  }

  return 0;
}