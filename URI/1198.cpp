#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  long long a, b;
  while (cin >> a >> b) {
    cout << abs(b - a) << endl;
  }

  return 0;
}