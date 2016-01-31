#include<bits/stdc++.h>
using namespace std;

int main() {
  long long fib[222];
  fib[0] = 0;
  fib[1] = 1;
  fib[2] = 1;

  for (int i = 3; i < 100; ++i) fib[i] = fib[i - 1] + fib[i - 2];

  int t,n;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n;
    cout << "Fib("<< n <<") = " << fib[n] << endl;
  }

  return 0;
}
