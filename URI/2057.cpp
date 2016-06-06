#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  cout << ((a + b + c) + 24) % 24 << endl;
  return 0;
}