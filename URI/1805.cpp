#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

long long sum(long long n) {
  return (n * (n + 1)) / 2LL;
}

int main() {
  int a, b;
  while (cin >> a >> b) {
    cout << sum(b) - sum(a - 1) << endl;
  }

  return 0;
}