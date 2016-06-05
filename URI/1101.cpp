#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " < (x) << endl;

int main() {
  int a, b;

  while (cin >> a >> b) {
    if (a <= 0 || b <= 0) break;
    if (a > b) swap(a, b);

    int sum = a;
    cout << a;
    for (int i = a + 1; i <= b; ++i) {
      cout << " " << i;
      sum += i;
    }

    cout << " Sum=" << sum << endl;
  }

  return 0;
}