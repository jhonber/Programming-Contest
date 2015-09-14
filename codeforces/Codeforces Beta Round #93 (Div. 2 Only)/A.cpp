// http://codeforces.com/contest/127/problem/A

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

double d (pair<double, double> x, pair<double, double> y) {
  double a = x.second - y.second;
  double b = x.first - y.first;
  return sqrt( (a * a) + (b * b) );
}

int main() {
  int n, k;
  cin >> n >> k;

  vector< pair<double,double> > v(n);
  for (int i = 0; i < n; ++i) {
    double x, y;
    cin >> x >> y;
    v[i] = make_pair(x,y);
  }

  double ans = 0;
  int i = 0, j = 1;
  while (true) {
    i %= n;
    j = (i + 1) % n;
    ans += d(v[i], v[j]);
    if (j == n - 1) break;
    i ++;
  }


  printf("%.10lf", (ans / 50.) * k);
  return 0;
}