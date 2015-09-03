// http://codeforces.com/contest/190/problem/B

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

double d(double x1, double y1, double x2, double y2){ return sqrt(((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1))); }

int main(){ __
  double x1,y1,r1;
  double x2,y2,r2;

  cin >> x1 >> y1 >> r1;
  cin >> x2 >> y2 >> r2;

  double dist = d(x1,y1,x2,y2);
  double t = r1 + r2;
  double ans;

  if (dist + min(r1,r2) <= max(r1,r2))
    ans = (max(r1,r2)-(dist+min(r1,r2))) / 2.0;
  else if (dist-t >= 0)
    ans = (dist-t) / 2.0;
  else
    ans = 0.0;

  printf("%.10lf", ans);
  return 0;
}