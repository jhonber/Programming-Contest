// http://codeforces.com/contest/279/problem/A

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

int main() {
  int x, y;
  cin >> x >> y;

  int turns = 0;
  int lim = 2;
  int dxx [4] = {1, 0, -1,  0};
  int dyy [4] = {0, 1,  0, -1};

  int x2 = 0, y2 = 0;
  int f = false;
  while (true) {
    for (int l = 1; l <= lim; ++l) {
      if (x2 == x and y2 == y) {
        if (f) turns --;
        cout << turns;
        return 0;
      }

      f = false;
      x2 += dxx[turns % 4];
      y2 += dyy[turns % 4];

      if (l * 2 == lim) {
        f = true;
        turns ++;
      }
    }
    turns ++;
    f = true;
    lim += 2;
  }

  return 0;
}