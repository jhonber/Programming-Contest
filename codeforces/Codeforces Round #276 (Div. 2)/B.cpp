// http://codeforces.com/contest/485/problem/B

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

int main(){ __
  int n;
  cin >> n;

  long long minx = INT_MAX;
  long long maxx = -INT_MAX;
  long long miny = INT_MAX;
  long long maxy = -INT_MAX;

  for (int i = 0; i < n; ++i) {
    long long x,y;
    cin >> x >> y;
    minx = min(minx,x);
    maxx = max(maxx,x);
    miny = min(miny,y);
    maxy = max(maxy,y);
  }

  long long tmp = max(maxx - minx , maxy - miny);
  cout << tmp*tmp;
  return 0;
}