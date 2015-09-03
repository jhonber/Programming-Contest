// http://codeforces.com/contest/227/problem/A

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

struct point {
  long long x;
  long long y;
  point () {}
  point (long long x_, long long y_):x (x_), y (y_) {}

  /**
   * Compara el punto C con el segmento AB.
   * Retorna 0 si son colineales.
   * Mayor que cero si está a la izquierda.
   * Menor que cero si está a la derecha.
   */
  long long cross (const point & a, const point & b) {
    return (b.x - a.x) * (y - a.y) - (x - a.x) * (b.y - a.y);
  }
};


int main(){ __
  point a,b,c;
  cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

  long long cross = c.cross(a,b);
  if (cross < 0) cout << "RIGHT";
  else if (cross == 0) cout << "TOWARDS";
  else cout << "LEFT";

  return 0;
}