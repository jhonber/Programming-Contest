#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n = 100;
  vector<double> v(n);

  for (int i = 0; i < n; ++i) cin >> v[i];

  for (int i = 0; i < n; ++i) if (v[i] <= 10)
    printf("A[%d] = %.1lf\n", i, v[i]);

  return 0;
}