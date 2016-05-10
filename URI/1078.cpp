#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < 10; ++i) {
    cout << i + 1 << " x " << n << " = " << (i + 1) * n << endl;
  }

  return 0;
}