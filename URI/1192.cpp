#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  string s;
  while (n --> 0) {
    cin >> s;

    int a = s[0] - '0';
    int b = s[2] - '0';

    if (a == b) {
      cout << a * b << endl;
    }
    else if (isupper(s[1])) {
      cout << b - a << endl;
    }
    else {
      cout << a + b << endl;
    }
  }

  return 0;
}