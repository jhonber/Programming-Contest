#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n = 20;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  int j = 0;
  for (int i = n - 1; i >= 0; --i, ++j) {
    printf("N[%d] = %d\n", j, v[i]);
  }

  return 0;
}