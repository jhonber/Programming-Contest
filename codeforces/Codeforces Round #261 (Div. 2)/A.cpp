// http://codeforces.com/contest/459/problem/A

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main(){ __
  int x1,y1,x2,y2;

  cin >> x1 >> y1 >> x2 >> y2;

  if (x1 == x2) {
    int dif = abs(y2-y1);
    cout << x1 + dif << " " << y1 << " " << x2 + dif << " " <<  y2;
    return 0;
  }

  if (y1 == y2) {
    int dif = abs(x2-x1);
    cout << x1 << " " << y1 + dif << " " << x2 << " " <<  y2 + dif;
    return 0;
  }

  int x3 = min(x1,x2);
  int y3 = min(y1,y2);
  int dif = abs(x2 - x1);

  if (dif != abs(y2-y1)) {
    cout << -1;
    return 0;
  }

  int x,y;
  x = x3;
  y = y3 + dif;
  if (x == x1 && y == y1 || x == x2 && y == y2){}
  else
    cout << x << " " << y << " ";

  x += dif;
  if (x == x1 && y == y1 || x == x2 && y == y2){}
  else
    cout << x << " " << y << " ";

  y -= dif;
  if (x == x1 && y == y1 || x == x2 && y == y2){}
  else
    cout << x << " " << y << " ";

  x -= dif;
  if (x == x1 && y == y1 || x == x2 && y == y2){}
  else
    cout << x << " " << y << " ";


  return 0;
}