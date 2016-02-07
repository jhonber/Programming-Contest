#include<bits/stdc++.h>
using namespace std;

int fact(int x) {
  if (x <= 1) return 1;

  int f = 1;
  for (int i = 1; i <= x; ++i) f *= i;
  return f;
}

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;

    int ans = 0;
    int i = 1;
    while (n > 0) {
      ans += fact(i) * (n % 10);
      n /= 10;
      i ++;
    }

    cout << ans << endl;
  }

  return 0;
}
