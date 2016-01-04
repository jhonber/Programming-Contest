// http://codeforces.com/contest/606/problem/B

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

bool check(int x0, int y0, int x, int y) {
  return x0 > x || x0 < 1 || y0 > y || y0 < 1;
}

pair<int, int> go (int x0, int y0, int x, int y, char dir) {
  int x2 = x0, y2 = y0;
  if (dir == 'U') x2 --;
  else if (dir == 'D') x2 ++;
  else if (dir == 'L') y2 --;
  else if (dir == 'R') y2 ++;

  if (!check(x2, y2, x, y)) return {x2, y2};
  return {x0, y0};
}

int main() {
  int x,y,x0,y0;
  cin >> x >> y >> x0 >> y0;

  string s;
  cin >> s;

  int cnt = 1;
  cout << "1 ";

  int mat[555][555];
  memset(mat, 0, sizeof mat);

  pair<int, int> bef = {x0, y0};
  mat[x0][y0] = true;

  for (int i = 0; i < s.size() - 1; ++i) {
    pair<int, int> cur = go(bef.first, bef.second, x, y, s[i]);
    if (mat[cur.first][cur.second]) {
      cout << "0 ";
    }
    else {
      cout << "1 ";
      mat[cur.first][cur.second] = true;
      cnt ++;
    }
    bef = cur;
  }

  cout << x * y - cnt;
  return 0;
}