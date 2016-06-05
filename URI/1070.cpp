#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " < (x) << endl;

int main() {
  int x;
  cin >> x;

  int cnt = 0;
  while (cnt < 6) {
    if (x % 2 != 0) {
      cout << x << endl;
      cnt ++;
    }
    x ++;
  }

  return 0;
}