// http://codeforces.com/contest/230/problem/A

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int s,n;

int main(){__
  cin >> s >> n;

  vector< pair<int,int> > v;
  for(int i=0; i<n; ++i){
    int x,y;
    cin >> x >> y;
    v.push_back(make_pair(x,y));
  }

  sort(all(v));

  int ss = s;
  for(int i=0; i<n; ++i){
    if(v[i].first < ss){
      ss += v[i].second;
    }
    else {
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";

  return 0;
}