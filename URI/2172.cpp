#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  long long a, b;
  while (cin >> a >> b) {
    if (a + b == 0) break;
    cout << a * b << endl;
  }
  return 0;
}