#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  int pos = 1;
  int mmax = 0;
  int ans = 0;

  while (cin >> n) {
    if (n > mmax) {
      ans = pos;
      mmax = n;
    }

    pos ++;
  }

  cout << mmax << endl << ans << endl;

  return 0;
}