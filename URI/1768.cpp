#include<bits/stdc++.h>
using namespace std;

string fix(int n, int x) {
  string s;
  for (int i = 0; i < n; ++i) s += "*";
  for (int i = 0; i < x; ++i) s = " " + s;
  return s;
}


int main() {
  int n;
  while (cin >> n) {
    int k = n / 2;
    for (int i = 1; i <= n; i += 2) {
      cout << fix(i, k) << endl;
      k --;
    }

    k = n / 2;
    cout << fix(1, k) << endl;
    cout << fix(3, k - 1) << endl << endl;
  }

  return 0;
}
