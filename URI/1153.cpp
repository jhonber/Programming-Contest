#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  long long f[14];
  f[1] = 1;
  for (int i = 2; i < 14; ++i) {
    f[i] = i * f[i - 1];
  }

  cout << f[n] << endl;
  return 0;
}