// http://codeforces.com/contest/474/problem/C

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

const double EPS = 1e-6;

struct point {
  int x, y, a, b;
  point() {}
};

point rotation (point p) {
  point p2 = p;
  p2.x -= p.a;
  p2.y -= p.b;

  int t = -p2.y;
  p2.y = p2.x;
  p2.x = t;

  p2.x += p.a;
  p2.y += p.b;

  return p2;
}
long long d (long long x1, long long y1, long long x2, long long y2) {
  return ( ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)) );
}

bool check (vector<point> &pts) {
  set<long long> ds;
  for (int i = 0; i < 4; ++i)
    for (int j = i + 1; j < 4; ++j)
      ds.insert( d(pts[i].x, pts[i].y, pts[j].x, pts[j].y) );
 
  return ds.size() == 2;
}

int main(){ __
  int n,x,y,a,b;
  cin >> n;

  vector<point> pts[n];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 4; ++j) {
      cin >> x >> y >> a >> b;
      point t; t.x = x; t.y = y; t.a = a; t.b = b;
      pts[i].push_back(t);
    }
  }

  for (int i = 0; i < n; ++i) {
    vector<point> tmp[4];
    for (int j = 0; j < 4; ++j) {
      tmp[j].push_back( pts[i][j] );
      for (int k = 0; k < 3; ++k) {
        tmp[j].push_back( rotation(tmp[j][k]) );
      }
    }

    int f = false;
    for (int j = 0; j < 4 and !f; ++j) {
      for (int k = 0; k < 4 and !f; ++k) {
        for (int l = 0; l < 4 and !f; ++l) {
          for (int m = 0; m < 4; ++m) {
            int ans = j + k + l + m;
            point t[] = { tmp[0][j], tmp[1][k], tmp[2][l], tmp[3][m] };
            vector<point> tt (t, t + 4);
            set< pair<int,int> > st;
            for (int x = 0; x < 4; ++x){
              st.insert( make_pair(tt[x].x, tt[x].y) );
            }

            if (st.size() != 4) continue;

            if ( check(tt) ) {
              cout << ans << endl;
              f = true;
              break;
            }
          }
        }
      }
    }
    if (!f) cout << -1 << endl;
  }

  return 0;
}