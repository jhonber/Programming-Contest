// http://codeforces.com/contest/617/problem/C

#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;
#define inf 1e15

double dist(double x1, double y1, double x2, double y2) {
  return sqrt(((x2 - x1)*(x2 - x1)) + ((y2 - y1)*(y2 - y1)));
}

int main() {
  int n;
  cin >> n;

  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  vector< pair<double, double> > distances(n);
  vector< pair<double, double> > v(n);
  for (int i = 0; i < n; ++i) {
    double x, y;
    cin >> x >> y;
    distances[i] = {dist(x,y,x1,y1), dist(x,y,x2,y2)};
  }

  double ans = inf;
  for (int i = 0; i < n; ++i) {
    double r1 = distances[i].first;
    double r2 = 0;
    for (int j = 0; j < n; ++j) {
      if (distances[j].first > r1) {
        if (r2 < distances[j].second)
          r2 = distances[j].second;
      }
    }
    double tmp = r1 * r1 + r2 * r2;
    if (tmp < ans) {
      ans = tmp;
    }
  }

  double ans2 = inf;
  for (int i = 0; i < n; ++i) {
    double r1 = distances[i].second;
    double r2 = 0;
    for (int j = 0; j < n; ++j) {
      if (distances[j].second > r1) {
        if (r2 < distances[j].first)
          r2 = distances[j].first;
      }
    }
    double tmp = r1 * r1 + r2 * r2;
    if (tmp < ans2) {
      ans2 = tmp;
    }
  }


  if (ans < ans2) printf("%.0lf", ans);
  else printf("%.0lf", ans2);
  return 0;
}