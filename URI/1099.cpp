#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " < (x) << endl;

int main() {
  int n;
  cin >> n;

  while (n --> 0) {
    int a, b;
    cin >> a >> b;

    if (a > b) swap(a, b);

    int sum = 0;
    for (int i = a + 1; i < b; ++i) if (i % 2 != 0) sum += i;
    cout << sum << endl;
  }

  return 0;
}