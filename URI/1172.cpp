#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " < (x) << endl;

int main() {
  int n = 10;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;

    if (x <= 0) x = 1;
    cout << "X[" << i << "] = " << x << endl;
  }

  return 0;
}