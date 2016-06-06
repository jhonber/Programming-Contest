#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  long long a, b, c;
  while (cin >> a >> b >> c) {
    cout << (long long)sqrt((a * b * 100) / c) << endl;
  }
  return 0;
}