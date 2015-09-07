// http://codeforces.com/contest/560/problem/B

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
  int a, b, a1, b1, a2, b2;
  cin >> a >> b >> a1 >> b1 >> a2 >> b2;

  int ans = false;
  int aa = max(a, b);
  int bb = min(a, b);

  if (a1 <= bb and b1 <= aa) {
    int x1 = bb;
    int y1 = aa - b1;
    int x2 = bb - a1;
    int y2 = aa;

    if (x1 >= a2 and y1 >= b2 or x2 >= a2 and y2 >= b2) ans = true;
    if (x1 >= b2 and y1 >= a2 or x2 >= b2 and y2 >= a2) ans = true;
  }

  if (a2 <= bb and b2 <= aa) {
    int x1 = bb;
    int y1 = aa - b2;
    int x2 = bb - a2;
    int y2 = aa;

    if (x1 >= a1 and y1 >= b1 or x2 >= a1 and y2 >= b1) ans = true;
    if (x1 >= b1 and y1 >= a1 or x2 >= b1 and y2 >= a1) ans = true;
  }

  if (b1 <= bb and a1 <= aa) {
    int x1 = bb;
    int y1 = aa - a1;
    int x2 = bb - b1;
    int y2 = aa;

    if (x1 >= a2 and y1 >= b2 or x2 >= a2 and y2 >= b2) ans = true;
    if (x1 >= b2 and y1 >= a2 or x2 >= b2 and y2 >= a2) ans = true;
  }

  if (b2 <= bb and a2 <= aa) {
    int x1 = bb;
    int y1 = aa - a2;
    int x2 = bb - b2;
    int y2 = aa;

    if (x1 >= a1 and y1 >= b1 or x2 >= a1 and y2 >= b1) ans = true;
    if (x1 >= b1 and y1 >= a1 or x2 >= b1 and y2 >= a1) ans = true;
  }

  cout << (ans ? "YES" : "NO");

  return 0;
}