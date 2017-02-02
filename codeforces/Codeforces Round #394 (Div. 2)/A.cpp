// http://codeforces.com/contest/761/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int a, b;
  cin >> a >> b;


  for (int i = 1; i <= 333; ++i) {
    for (int j = 1; j <= 333; ++j) {
      int aa = 0;
      int bb = 0;
      for (int k = i; k <= j; ++k) {
        if (k % 2 == 0) aa ++;
        else bb ++;

        if (a == aa && b == bb) {
          cout << "YES" << endl;
          return 0;
        }
      }
    }
  }

  cout << "NO" << endl;
  return 0;
}