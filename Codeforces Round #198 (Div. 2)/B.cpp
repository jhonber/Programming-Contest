// http://codeforces.com/contest/340/problem/B

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

struct point {
  double x;
  double y;

  point () {}
  point (double x_, double y_):x (x_), y (y_) {}

  bool operator < (const point & other) const {
    if (x == other.x)
      return y < other.y;
    return x < other.x;
  }

  double dist (const point & other) {
    double a = x - other.x;
    double b = y - other.y;
    return sqrt (a * a + b * b);
  }
  /**
  * Compara el punto C con el segmento AB.
  * Retorna 0 si son colineales.
  * Mayor que cero si está a la izquierda.
  * Menor que cero si está a la derecha.
  */
  int cross (const point & a, const point & b) {
    return (b.x - a.x) * (y - a.y) - (x - a.x) * (b.y - a.y);
  }

  void multEsc (int e) {
    this->x *= e;
    this->y *= e;
  }

};

double PolygonArea(const vector<point> &p){
  double r = 0.0;
  for (int i=0; i<p.size(); ++i){
    int j = (i+1) % p.size();
    r += p[i].x*p[j].y - p[j].x*p[i].y;
  }
  return r/2.0;
}

int main(){ __
  int n;
  cin >> n;

  point p;
  vector<point> pts;
  for (int i = 0; i < n; ++i) {
    cin >> p.x >> p.y;
    pts.push_back(p);
  }

  vector<point> tmp(3);
  double ans = 0.0;
  for (int i = 0; i < n; ++i) {
    tmp[0] = pts[i];
    for (int j = i + 1; j < n; ++j) {
      tmp[1] = pts[j];
      double area1 = 0.0;
      double area2 = 0.0;
      for (int k = 0; k < n; ++k) {
        if (j == k || i == j) continue;
        int c = pts[k].cross(pts[i], pts[j]);
        tmp[2] = pts[k];

        double area = abs(PolygonArea(tmp));
        if (c > 0)
          area1 = max(area, area1);
        else
          area2 = max(area, area2);
      }
      if (area1 > 0.0 && area2 > 0.0)
        ans = max(area1 + area2, ans);
    }
  }

  cout.precision(16);
  cout << ans;

  return 0;
}