#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  long long p = 1;
  while (n --> 0) p *= 3;

  cout << p << endl;
  return 0;
}