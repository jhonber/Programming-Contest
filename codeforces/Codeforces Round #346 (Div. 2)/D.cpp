// http://codeforces.com/contest/659/problem/D

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

struct p {
  int x, y;
  p() {}
  p(int x_, int y_) {
    x = x_;
    y = y_;
  }
};

bool check(int a, int b) {
  int ans = 0;
  if (a == 1 && b == 0) ans ++;
  if (a == 2 && b == 1) ans ++;
  if (a == 0 && b == 3) ans ++;
  if (a == 3 && b == 2) ans ++;

  return ans;
}

int main() {
  int n;
  cin >> n;

  vector<p> route;
  for (int i = 0; i < n + 1; ++i) {
    int x, y;
    cin >> x >> y;

    route.push_back(p(x, y));
  }

  int ans = 0;
  int a = 0, b;
  for (int i = 1; i <= n; ++i) {
    if (route[i - 1].x == route[i].x) {
      if (route[i - 1].y > route[i].y) {
        b = 2;
      }
      else {
        b = 0;
      }

      ans += check(a, b);
    }
    else {
      if (route[i - 1].x > route[i].x) {
        b = 3;
      }
      else {
        b = 1;
      }

      ans += check(a, b);
    }
    a = b;
  }

  cout << ans;

  return 0;
}