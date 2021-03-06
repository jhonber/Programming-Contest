// http://codeforces.com/contest/710/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

bool check(int x, int y) {
  return x < 0 || x > 7 || y < 0 || y > 7;
}

int main() {
  string s;
  cin >> s;

  int x = s[0] - 'a';
  int y = 8 - (s[1] - '0');

  int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
  int dy[8] = {-1, 0, 1,1,1,0,-1,-1};


  int ans = 0;
  for (int i = 0; i < 8; ++i) {
    if (!check(dx[i] + x, dy[i] + y)) ans ++;
  }

  cout << ans << endl;
  return 0;
}