// http://codeforces.com/contest/165/problem/A

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

int main(){__
  int n, x, y;
  cin >> n;

  vector< pair<int,int> > points;

  for(int i=0; i<n; ++i){
    cin >> x >> y;
    points.push_back( make_pair(x,y) );
  }

  int ans = 0;
  for(int i=0; i<n; ++i){
    pair<int,int> act = points[i];
    int a=0,b=0,c=0,d=0;
    for(int j=0; j<n; ++j){
      if(i==j) continue;
      if( points[j].first > act.first && points[j].second == act.second )
        a++;

      if( points[j].first < act.first && points[j].second == act.second )
        b++;

      if( points[j].first == act.first && points[j].second < act.second )
        c++;

      if( points[j].first == act.first && points[j].second > act.second )
        d++;
    }
    if( a && b && c && d) ans ++;
  }

  cout << ans;

  return 0;
}