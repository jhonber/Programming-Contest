// http://codeforces.com/contest/424/problem/B

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

int main() { __
  int n,tot;
  cin >> n >> tot;

  int people[n];
  vector<point> pts(n);
  point t;
  int tmp;
  for (int i = 0; i < n; ++i) {
    cin >> t.x >> t.y >> tmp;
    pts[i] = t;
    people[i] = tmp;
  }

  point zero;
  zero.x = 0.0; zero.y = 0.0;

  vector< pair<double,int> > todo(n);
  for (int i = 0; i < n; ++i) {
    todo[i].first = pts[i].dist(zero);
    todo[i].second = i;
  }

  sort(all(todo));

  double ans = INT_MAX;
  int cnt = 0;
  while (tot < 1e6 && cnt < n) {
    tot += people[todo[cnt].second];
    ans = todo[cnt].first;
    cnt ++;
  }

  cout.precision(16);
  cout << (tot < 1e6 ? -1 : ans);
  return 0;
}