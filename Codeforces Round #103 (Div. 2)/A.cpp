// http://codeforces.com/contest/144/problem/A

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

const int INF = 10e8;

int main(){__
  int n;
  cin >> n;

  int v[n];
  for(int i=0; i<n; ++i)
    cin >> v[i];

  int min = INF, posmin;
  int max = -INF, posmax;

  for(int i=n-1; i>=0; --i){
    if( v[i]<min ){
      min = v[i];
      posmin = i;
    }
  }

  for(int i=0; i<n; ++i){
    if( v[i]>max ){
      max = v[i];
      posmax = i;
    }
  }

  int ans = posmax+(n-1-posmin);
  cout << (posmin < posmax ? ans-1 : ans);

  return 0;
}