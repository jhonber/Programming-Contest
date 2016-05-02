#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;
    cout << 1;
    for (int i = 2; i <= n; ++i) cout << " " << i;
    cout << endl;
  }

  return 0;
}