// http://codeforces.com/contest/427/problem/B

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
  int n,t,c;
  cin >> n >> t >> c;

  int v[n+10];
  for(int i=0; i<n; ++i){
    cin >> v[i];
  }

  int ans = 0;
  int cont = 0;
  for(int i=0; i<n; ++i){
    if(v[i]<=t){
      cont ++;
    }
    if( v[i]>t || i==n-1){
      if(cont>=c){
        if(c==1)
          ans += cont;
        else if(cont==c)
          ans ++;
        else
          ans += (cont-c) + 1;
      }
      cont = 0;
    }
  }

  cout << ans;

  return 0;
}
