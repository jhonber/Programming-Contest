// http://codeforces.com/contest/791/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int a, b;
  cin >> a >> b;

  int i = 1;
  while (true) {
    a *= 3;
    b *= 2;
    if (a > b) break;
    i ++;
  }

  cout << i << endl;
  return 0;
}