#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;

  cin >> n;

  for (int i = 2; i <= n; ++i) {
    if ((i * i) % 2 == 0) cout << i << "^2 = " << i * i << endl;
  }

  return 0;
}