#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int a, n;
  while (cin >> a >> n) {
    while (n <= 0) cin >> n;

    long long sum = 0;
    for (int i = a, j = 0; j < n; ++i, ++j) {
      sum += i;
    }

    cout << sum << endl;
  }

  return 0;
}