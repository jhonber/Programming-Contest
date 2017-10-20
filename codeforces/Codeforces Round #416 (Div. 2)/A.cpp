// http://codeforces.com/contest/811/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int a, b;
  while (cin >> a >> b) {
    int tot = 1;
    while (true) {
      if (tot % 2 != 0) {
        a -= tot;
        if (a < 0) {
          cout << "Vladik" << endl;
          break;
        }
      }
      else {
        b -= tot;
        if (b < 0) {
          cout << "Valera" << endl;
          break;
        }
      }
      tot ++;
    }
  }

  return 0;
}