// http://codeforces.com/contest/600/problem/D

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

long double INF = 1e100;
long double EPS = 1e-12;
const long double pi = acos(-1);

struct PT {
  long double x, y;
  PT() {}
  PT(long double x, long double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (long double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (long double c)     const { return PT(x/c,   y/c  ); }
};

long double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
long double dist2(PT p, PT q)   { return dot(p-q,p-q); }
long double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const PT &p) {
  os << "(" << p.x << "," << p.y << ")";
}

// rotate a point CCW or CW around the origin
PT RotateCCW90(PT p)   { return PT(-p.y,p.x); }
PT RotateCW90(PT p)    { return PT(p.y,-p.x); }
PT RotateCCW(PT p, long double t) {
  return PT(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t));
}

// computes the circular segment of a circle with radious r
// and central angle aplha
long double sector(long double r, long double alpha) {
  return r * r * 0.5 * (alpha - sin(alpha));
}

void solve() {
  long double x, y, r, x1, y1, r1;
  cin >> x >> y >> r >> x1 >> y1 >> r1;

  cout << fixed << setprecision(20);
  long double d = sqrt(dist2(PT(x, y), PT(x1, y1)));
  if (d >= r + r1) {
    cout << 0 << endl;
    return;
  }
  if (d + r <= r1) {
//    printf("%.10lf\n", pi * r * r);
    cout << pi * r * r << endl;
    return;
  }
  if (d + r1 <= r) {
//    printf("%.10lf\n", pi * r1 * r1);
    cout << pi * r1 * r1 << endl;
    return;
  }

  // using law of cosines
  long double ans = sector(r, 2 * acos((r * r + d * d - r1 * r1) / (2.0 * r * d)));
  ans += sector(r1, 2 * acos((r1 * r1 + d * d - r * r) / (2.0 * r1 * d)));

//  printf("%.10llf\n", ans);
    cout << ans << endl;
}

int main() {
  solve();
  return 0;
}
