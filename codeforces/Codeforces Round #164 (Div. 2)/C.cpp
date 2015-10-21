// http://codeforces.com/contest/268/problem/C

#include<bits/stdc++.h>
using namespace std;

double d(int x1, int y1, int x2, int y2) {
  return sqrt( (((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))) );
}

bool check(vector<int> &x, vector<int> &y) {
  for (int i = 0; i < x.size(); ++i) {
    for (int j = i + 1; j < x.size(); ++j) {
      double dt = d(x[i], y[i], x[j], y[j]);
      if (dt - (int)dt == 0.0) {
        printf("%d %d, %d %d => %lf\n", x[i], y[i], x[j], y[j], dt);
        return false;
      }
    }
  }
  return true;
}

int main() {
  int n, m;
  cin >> n >> m;

  int mm = min(n, m);
  vector<int> x(mm + 1), y(mm + 1);

  int a = 0, b = mm;
  for (int i = 0; i < mm + 1; ++i) {
    x[i] = a;
    y[i] = b;
    a ++; b --;
  }

  cout << x.size() << endl;
  for (int i = 0; i < x.size(); ++i) cout << x[i] << " " << y[i] << "\n";

  if (!check(x, y)) assert(false);
  return 0;
}