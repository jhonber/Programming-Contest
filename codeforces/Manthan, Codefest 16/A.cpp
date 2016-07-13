// http://codeforces.com/contest/633/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int found = false;
  for (int i = 0; i < 100000; ++i) {
    int x = (c - (b * i)) / a;
    if (x < 0 ) continue;
    if (a * x + b * i == c) {
      found = true;
      break;
    }
  }

  cout << (found ? "Yes" : "No") << endl;
  return 0;
}