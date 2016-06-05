#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " < (x) << endl;

int main() {
  int a, b;
  a = 0;
  b = 1;

  int n;
  cin >> n;

  if (n == 0) cout << a;
  else if (n == 1) cout << b;
  else {
    cout << a;

    int c;
    for (int i = 0; i + 1 < n; ++i) {
      c = a + b;
      cout << " " << b;
      a = b;
      b = c;
    }
  }
  cout << endl;

  return 0;
}