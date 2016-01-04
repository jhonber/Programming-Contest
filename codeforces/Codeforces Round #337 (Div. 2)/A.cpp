// http://codeforces.com/contest/610/problem/A

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  if (n % 2 != 0) {
    cout << 0;
    return 0;
  }

  n /= 2;

  if (n % 2 == 0) cout << (n / 2) - 1;
  else cout << n / 2;

  return 0;
}