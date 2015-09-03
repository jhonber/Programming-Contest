// http://codeforces.com/contest/43/problem/A

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
  int n;
  cin >> n;

  map<string,int> mapa;
  for(int i=0; i<n;++i){
    string s;
    cin >> s;
    mapa[s] ++;
  }

  string ans;
  int mmax = 0;
  foreach(x,mapa){
    if(x->second > mmax){
      mmax = x->second;
      ans = x->first;
    }
  }
  cout << ans;
  return 0;
}