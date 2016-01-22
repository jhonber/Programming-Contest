// http://codeforces.com/contest/620/problem/A

#include<bits/stdc++.h>
using namespace std;

int main() {
  int x, y, x2, y2;
  cin >> x >> y >> x2 >> y2;

  cout << max(abs(x - x2), abs(y - y2));
  return 0;
}