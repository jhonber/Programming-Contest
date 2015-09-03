// http://codeforces.com/contest/298/problem/B

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for (__typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

string next (int x, int y, int x2, int y2) {
  if (x == x2 and y < y2) return "N";
  if (x == x2 and y > y2) return "S";
  if (y == y2 and x > x2) return "W";
  if (y == y2 and x < x2) return "E";
  if (x > x2 and y < y2) return "WN";
  if (x < x2 and y < y2) return "EN";
  if (x > x2 and y > y2) return "WS";
  if (x < x2 and y > y2) return "ES";
}

pair<int, int> go(int x, int y, char dir) {
  if (dir == 'N') return make_pair(x, y + 1);
  if (dir == 'S') return make_pair(x, y - 1);
  if (dir == 'W') return make_pair(x - 1, y);
  if (dir == 'E') return make_pair(x + 1, y);
}

int main() {
  int t,x,y,x2,y2;
  cin >> t >> x >> y >> x2 >> y2;

  string s;
  cin >> s;

  for (int i = 0; i < t; ++i) {
    string s2 = next(x,y,x2,y2);
    for (int j = 0; j < s2.size(); ++j) if (s[i] == s2[j]) {
      pair<int, int> tmp = go(x,y,s[i]);
      x = tmp.first; y = tmp.second;
      break;
    }
    if (x == x2 and y == y2) {
      cout << i + 1;
      return 0;
    }
  }

  cout << -1;
  return 0;
}