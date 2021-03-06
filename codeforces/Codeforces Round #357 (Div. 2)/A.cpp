// http://codeforces.com/contest/681/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  int ans = false;
  for (int i = 0; i < n; ++i) {
    string s;
    int a, b;
    cin >> s >> a >> b;
    if (a >= 2400 && b - a > 0) {
      ans = true;
    }
  }

  cout << (ans ? "YES": "NO") << endl;
  return 0;
}