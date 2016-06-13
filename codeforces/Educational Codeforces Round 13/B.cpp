// http://codeforces.com/contest/678/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

bool isleap(int x) {
  return (x % 400 == 0 || (x % 4 == 0 && x % 100 != 0));
}

int main() {
  int y;
  cin >> y;
  y ++;

  int f = isleap(y - 1);
  long long cnt = (f ? 366 : 365);
  while (true) {
    if (cnt % 7 == 0 && f == isleap(y)) {
      cout << y << endl;
      break;
    }
    cnt += (isleap(y) ? 366 : 365);
    y ++;
  }

  return 0;
}