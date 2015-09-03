// http://codeforces.com/contest/37/problem/A

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;
#define MN 4004

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main(){
  int n;
  cin >> n;

  map<int,int> mapa;

  for(int i=0; i<n; ++i){
    int t;
    cin >> t;
    mapa[t] ++;
  }

  int mmax = 0;
  foreach(x,mapa)
    mmax = max(x->second,mmax);

  cout << mmax << " " << mapa.size();

  return 0;
}