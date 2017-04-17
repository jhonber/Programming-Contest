// http://codeforces.com/contest/801/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string x, y;
  cin >> x >> y;
  string ans;
  for (int i = 0; i < x.size(); ++i) {
    if (x[i] < y[i]) {
      cout << -1 << endl;
      return 0;
    }
  }

  cout << y << endl;

  return 0;
}