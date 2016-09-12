// http://codeforces.com/contest/712/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string s;
  cin >> s;

  int n = s.size();

  if (n % 2 != 0) {
    cout << -1 << endl;
    return 0;
  }

  map<char, int> dx, dy;
  dx['U'] = -1;
  dx['D'] =  1;
  dy['L'] = -1;
  dy['R'] =  1;

  int x = 0, y = 0;
  for (int i = 0; i < n; ++i) {
    x += dx[s[i]];
    y += dy[s[i]];
  }

  cout << (abs(x) + abs(y)) / 2 << endl;
  return 0;
}