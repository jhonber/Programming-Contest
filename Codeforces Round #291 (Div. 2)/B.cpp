// http://codeforces.com/contest/514/problem/B

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

int f;
void line_line_intersection(double x0, double y0,
    double x1, double y1,
    double x2, double y2,
    double x3, double y3){
#ifndef EPS
#define EPS 1e-9
#endif
  double t0 = (y3-y2)*(x0-x2)-(x3-x2)*(y0-y2);
  double t1 = (x1-x0)*(y2-y0)-(y1-y0)*(x2-x0);
  double det = (y1-y0)*(x3-x2)-(y3-y2)*(x1-x0);
  if (fabs(det) < EPS){
    //parallel
    if (fabs(t0) < EPS || fabs(t1) < EPS){
      //same line
//      printf("LINE\n");
    }else{
      //just parallel
//      printf("NONE\n");
    }
  }else{
    t0 /= det;
    t1 /= det;
    double x = x0 + t0*(x1-x0);
    double y = y0 + t0*(y1-y0);
    //intersection is point (x, y)
//    printf("POINT %.2lf %.2lf\n", x, y);
    f = true;
  }
}


int main() {
  int n;
  double x,y; cin >> n >> x >> y;

  vector< pair<double,double> > segts;
  for (int i = 0; i < n; ++i) {
    double x2,y2;
    cin >> x2 >> y2;
    segts.push_back(make_pair(x2,y2));
  }

  vector<int> mark(n,0);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int ff = true;
    if (mark[i]) continue;
    for (int j = 0; j < n; ++j) {
      if (mark[j] || i == j) continue;
      f = false;
      line_line_intersection(x, y, segts[i].first, segts[i].second, x, y, segts[j].first, segts[j].second);
      if(!f) mark[j] = true;
    }
    ans += ff;
    mark[i] = true;
  }

  cout << ans;

  return 0;
}