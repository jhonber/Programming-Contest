// http://codeforces.com/contest/469/problem/B

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

int main(){ __
  int p,q,l,r;

  cin >> p >> q >> l >> r;

  vector< pair<int,int> > z;

  for (int i=0; i<p; ++i) {
    int a,b;
    cin >> a >> b;
    z.push_back( make_pair(a,b) );
  }

  vector< pair<int,int> > x;
  for (int i=0; i<q; ++i) {
    int a,b;
    cin >> a >> b;
    x.push_back( make_pair(a,b) );
  }

  int ans = 0;
  for (int i=l; i<=r; ++i) {
    int f = false;
    for (int j=0; j<x.size(); ++j) {
      int a = x[j].first + i;
      int b = x[j].second + i;

      for (int k=0; k<z.size(); ++k) {
        if ( (a >= z[k].first && a <= z[k].second || b >= z[k].first && b <= z[k].second)
            || (a <= z[k].first && b >= z[k].first || a <= z[k].second && b >= z[k].second) ) {
          ans ++;
          f = true;
          break;
        }
      }
      if (f) break;
    }
  }

  cout << ans;
  return 0;
}