// http://codeforces.com/contest/822/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int a, b;
  while (cin >> a >> b) {
    a = min(a, b);

    int p = 1;
    for (int i = 1; i <= a; ++i) p *= i;

    cout << p << endl;
  }

  return 0;
}