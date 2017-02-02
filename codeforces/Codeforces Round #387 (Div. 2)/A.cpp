// http://codeforces.com/contest/747/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  int mm = INT_MAX;
  int a, b;
  for (int i = 1; i <= n ; ++i) {
    if (n % i != 0) continue;
    int other = n / i;
    if (other - i < mm && other >= i) {
      a = i;
      b = other;
      mm = b - a;
    }
  }

  cout << a << " " << b << endl;
  return 0;
}