// http://codeforces.com/contest/177/problem/D1

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

int main(){__

  int n,m,c;
  cin >> n >> m >> c;

  int v[n], vv[m];
  for(int i=0; i<n; ++i){
    cin >> v[i];
  }

  for(int i=0; i<m; ++i){
    cin >> vv[i];
  }

  for(int i=0; i<n; ++i){
    if(i+m > n) break;
    for(int j=0; j<m; ++j){
      v[i+j] += vv[j];
      v[j] %= c;
    }
  }

  for(int i=0; i<n; ++i){
    cout << " " << v[i] % c;
  }

  return 0;
}