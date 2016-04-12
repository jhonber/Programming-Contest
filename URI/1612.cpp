#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t;
  cin >> t;

  while (t --> 0) {
    int n;
    cin >> n;

    if (n <= 2) cout << 1 << endl;
    else cout << (int)ceil(n / 2.0) << endl;
  }

  return 0;
}