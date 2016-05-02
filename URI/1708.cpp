#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int x,y;

  while (cin >> x >> y) {
    int mx = max(x, y);
    int dif = abs(x - y);

    double ans = (double) mx / dif;
    cout << ceil(ans) << endl;
  }

  return 0;
}