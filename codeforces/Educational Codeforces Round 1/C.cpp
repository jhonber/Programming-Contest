// http://codeforces.com/contest/598/problem/C

#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

#define PI 3.141592653589793

struct point {
  long double ang;
  int ind;
  point () {}
  point (long double ang_, int ind_): ang (ang_), ind (ind_) {}
};

long double getAng(pair<int, int> i) {
  int f = false;
  if (i.second < 0) {
    i.second *= -1;
    f = true;
  }

  long double h = sqrt(i.first * i.first + i.second * i.second);
  long double ang = acos( i.first / h );

  if (f) ang = 2.0 * PI - ang;
  return ang;
}

bool comp(point i, point j) {
  return i.ang < j.ang;
}

int main() {
  int n;
  cin >> n;

  vector< point > v(n);

  for (int i = 0; i < n; ++i) {
    int x,y;
    cin >> x >> y;
    long double ang = getAng(make_pair(x, y));
    v[i] = point(ang, i + 1);
  }

  sort(v.begin(), v.end(), comp);

  int x, y;
  long double mx = INT_MAX;
  for (int i = 1; i < n; ++i) {
    long double ang = v[i].ang - v[i - 1].ang;
    if (mx > ang) {
      x = v[i].ind;
      y = v[i - 1].ind;
      mx = ang;
    }
  }

  long double ang = v[n - 1].ang - v[0].ang;
  if (mx > ang) {
    x = v[0].ind;
    y = v[n - 1].ind;
    mx = ang;
  }

  ang = v[0].ang + (2. * PI - v[n - 1].ang);
  if (mx > ang) {
    x = v[0].ind;
    y = v[n - 1].ind;
    mx = ang;
  }

  cout << x << " " << y << endl;

  return 0;
}