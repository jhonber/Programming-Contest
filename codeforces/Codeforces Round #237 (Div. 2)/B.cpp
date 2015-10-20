// http://codeforces.com/contest/404/problem/B

#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x << " = " << x << endl;

pair<double, double> f(double &a, double &d, double n) {
  double x = ceil((n * d) / a);
  double tmp = (x * a) - (n * d);
  int mod = (long long)x % 4;

  if (mod == 1) {
    tmp = a - tmp;
    return {tmp, 0.0};
  }
  else if (mod == 2) {
    tmp = a - tmp;
    return {a, tmp};
  }
  else if (mod == 3) {
    double x = tmp;
    return {x, a};
  }
  else {
    double y = tmp;
    return {0.0, y};
  }
}

int main() {
  double a, d, n;
  scanf("%lf %lf %lf", &a, &d, &n);

  for (int i = 1; i <= n; ++i) {
    pair<double, double> xy = f(a, d, i);
    printf("%.10lf %.10lf\n", xy.first, xy.second);
  }

  return 0;
}